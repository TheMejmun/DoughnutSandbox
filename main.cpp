#include <iostream>
#include "util/importer.h"
#include "graphics/renderer_v2.h"

class Object {
public:
    explicit Object(uint32_t i) : i(i) {
        std::cout << "Constructed" << std::endl;
    };

    Object(const Object &other): i(other.i) {
        std::cout << "Copied" << std::endl;
    };

    Object(Object &&other) noexcept: i(other.i) {
        std::cout << "Moved" << std::endl;
    };

    ~Object() {
        std::cout << "Destroyed" << std::endl;
    }

private:
    uint32_t i;
};

int main() {
#ifndef NDEBUG
    dn::log::init(true, true, true, true);
#else
    dn::log::init(true, false, false, true);
#endif

    dn::Window window{"Hello World"};
    dn::RendererV2 renderer{window};

    return 0;
}
