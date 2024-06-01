#pragma

#include <string>
namespace ariel{

class Resource {
public:
    virtual ~Resource() = default;
    virtual std::string getType() const = 0;
};
}
