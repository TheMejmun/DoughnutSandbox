#include <iostream>
#include "util/importer.h"
#include "graphics/renderer_v2.h"

int main() {
#ifndef NDEBUG
    dn::log::init(true, true, false, true);
#else
    dn::log::init(true, false, false, true);
#endif

    dn::Window window{"Hello World"};
    dn::RendererV2 renderer{&window, "Hello World"};

    return 0;
}
