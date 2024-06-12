#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

#define CATCH_CONFIG_MAIN
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Graph.hpp"
#include <vector>
#include <stdexcept>

using namespace std;

TEST_CASE("Test graph addition") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    ariel::Graph g2;
    std::vector<std::vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(weightedGraph);

    ariel::Graph g3 = g1 + g2;
    CHECK(g3.printGraph() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]\n");
}

TEST_CASE("Test graph multiplication") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    ariel::Graph g2;
    std::vector<std::vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}
    };
    g2.loadGraph(weightedGraph);

    ariel::Graph g4 = g1 * g2;
    CHECK_FALSE(g4.printGraph() == "[1, 2, 0]\n[2, 1, 2]\n[2, 0, 1]\n");
}

TEST_CASE("Invalid operations") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);

    ariel::Graph g2;
    std::vector<std::vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}
    };
    CHECK_THROWS(g2.loadGraph(weightedGraph));

    ariel::Graph g5;
    std::vector<std::vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}
    };
    g5.loadGraph(graph2);

    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    std::vector<std::vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}
    };
    g6.loadGraph(graph3);

    CHECK_THROWS(g1 + g6);
    ariel::Graph g7;
    std::vector<std::vector<int>> graph4 = {};
    CHECK_THROWS(g7.loadGraph(graph4));
}

TEST_CASE("Graph comparison operators") {
    ariel::Graph g1;
    std::vector<std::vector<int>> graph1 = {
        {0, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 3},
        {0, 0, 2, 3}
    };
    g1.loadGraph(graph1);

    ariel::Graph g2;
    std::vector<std::vector<int>> graph2 = {
        {0, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 1, 3},
        {0, 1, 2, 3}
    };
    g2.loadGraph(graph2);

    ariel::Graph g3;
    std::vector<std::vector<int>> graph3 = {
        {0, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 3},
        {0, 0, 2, 3}
    };
    g3.loadGraph(graph3);

    ariel::Graph g4;
    std::vector<std::vector<int>> greaterGraph = {
        {0, 1, 2},
        {1, 0, 3},
        {0, 2, 0}
    };
    g4.loadGraph(greaterGraph);

    ariel::Graph g5;
    std::vector<std::vector<int>> smallerGraph = {
        {0, 1},
        {1, 0}
    };
    g5.loadGraph(smallerGraph);

    ariel::Graph g6;
    std::vector<std::vector<int>> smallerEqualGraph = {
        {0, 1},
        {1, 0}
    };
    g6.loadGraph(smallerEqualGraph);

    SUBCASE("Greater than operator (>)") {
        CHECK(g2 > g1);
        CHECK_FALSE(g1 > g2);
        CHECK(g1 > g5);
        CHECK_FALSE(g5 > g1);
        CHECK(g1 > g4);
        CHECK_FALSE(g4 > g1);
    }

    SUBCASE("Greater than or equal operator (>=)") {
        CHECK(g2 >= g1);
        CHECK_FALSE(g1 >= g2);
        CHECK(g1 >= g5);
        CHECK_FALSE(g5 >= g1);
        CHECK(g1 >= g4);
        CHECK_FALSE(g4 >= g1);
        CHECK(g1 >= g3);
        CHECK(g3 >= g1);
        CHECK(g6 >= g5);
        CHECK(g5 >= g6);
    }

    SUBCASE("Less than operator (<)") {
        CHECK_FALSE(g2 < g1);
        CHECK(g1 < g2);
        CHECK_FALSE(g1 < g5);
        CHECK(g5 < g1);
        CHECK_FALSE(g1 < g4);
        CHECK(g4 < g1);
    }

    SUBCASE("Less than or equal operator (<=)") {
        CHECK_FALSE(g2 <= g1);
        CHECK(g1 <= g2);
        CHECK_FALSE(g1 <= g5);
        CHECK(g5 <= g1);
        CHECK_FALSE(g1 <= g4);
        CHECK(g4 <= g1);
        CHECK(g1 <= g3);
        CHECK(g3 <= g1);
        CHECK(g6 <= g5);
        CHECK(g5 <= g6);
    }
}


