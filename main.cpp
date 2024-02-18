#include <iostream>
#include "util/importer.h"
#include "graphics/renderer_v2.h"
#include "util/timer.h"
#include "io/input_manager.h"
#include "graphics/color_v2.h"

int main() {
#ifndef NDEBUG
    dn::log::init(true, true, false, true);
#else
    dn::log::init(true, false, false, true);
#endif

    dn::Color<dn::CIELAB> color(1.0f, 1.0f, 1.0f);
    dn::log::i(color.toString());
    return 0;

    dn::Window window{"Hello World"};
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
