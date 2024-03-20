
#include "util/importer.h"
#include "graphics/renderer_v2.h"
#include "util/timer.h"
#include "imgui.h"

int main() {
#ifndef NDEBUG
    dn::log::init(true, true, true, true);
#else
    dn::log::init(true, false, false, true);
#endif

    dn::Window window{"Hello World", 800, 600, true};
    dn::log::i("Test");
    dn::RendererV2 renderer{window};

    dn::FPSCounter fps{};

    dn::Time lastTimestamp = dn::now();
    double delta;
    while (!window.shouldClose()) {
        dn::Time time = dn::now();
        delta = dn::duration(lastTimestamp, time);
        lastTimestamp = time;

        fps.update(delta);
        dn::log::i("FPS:", fps.currentFPS());

        window.poll();

        renderer.drawFrame(delta);
    }

    return 0;
}
