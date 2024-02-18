#include <iostream>
#include "util/importer.h"
#include "graphics/renderer_v2.h"
#include "util/timer.h"
#include "io/input_manager.h"

int main() {
#ifndef NDEBUG
    dn::log::init(true, true, false, true);
#else
    dn::log::init(true, false, false, true);
#endif

    dn::Window window{"Hello World", 640, 400, false};
    InputController im{window.mGlfwWindow};
    dn::RendererV2 renderer{window};

    dn::Time lastTimestamp = dn::now();
    double delta;
    while (!window.shouldClose()) {
        dn::Time time = dn::now();
        delta = dn::duration(lastTimestamp, time);
        lastTimestamp = time;

        im.update();

        renderer.drawFrame(delta);
    }

    return 0;
}
