#include <iostream>
#include "util/importer.h"
#include "graphics/renderer_v2.h"
#include "util/timer.h"

int main() {
#ifndef NDEBUG
    dn::log::init(true, true, false, true);
#else
    dn::log::init(true, false, false, true);
#endif

    try {
        dn::Window window{"Hello World"};
        dn::RendererV2 renderer{window};

        dn::Time lastTimestamp = dn::now();
        double delta;
        while (!window.shouldClose()) {
            dn::Time time = dn::now();
            delta = dn::duration(lastTimestamp, time);
            lastTimestamp = time;

            renderer.drawFrame(delta);
            dn::log::flush();
        }

    } catch (const std::exception &e) {
        dn::log::e(e.what());
        dn::log::flush();
        return EXIT_FAILURE;
    }

    dn::log::flush();
    return 0;
}
