#include <iostream>
#include "util/importer.h"
#include "graphics/renderer_v2.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Doughnut::Window window{"Hello World"};
    Doughnut::RendererV2 renderer{&window, "Hello World"};

    return 0;
}
