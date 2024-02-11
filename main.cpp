#include <iostream>
#include "util/importer.h"
#include "graphics/renderer_v2.h"

int main() {
#ifndef NDEBUG
    dn::log::init(true, true, true, true);
#else
    dn::log::init(true, false, false, true);
#endif

    try {

        dn::Window window{"Hello World"};
        dn::RendererV2 renderer{window};

    } catch (const std::exception &e) {
        dn::log::e(e.what());
        dn::log::flush();
        return EXIT_FAILURE;
    }

    return 0;
}
