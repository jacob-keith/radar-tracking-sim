#include <iostream>
#include "target.h"
#include "world.h"
#include "config.h"
#include "radar.h"

int main() {
    Config config;

    std::cout << config.dt << " " << config.max_range << std::endl;

    Target target1(1, 3000.0, 4000.0, 0.0, 0.0);
    Target target2(2, 25000.0, 0.0, 0.0, 0.0);

    World world;
    world.addTarget(target1);
    world.addTarget(target2);

    Radar radar(0.0, 0.0, config);
    std::vector<Detection> detections = radar.scan(world, 0.0);
    for (const Detection& detection : detections) {
        std::cout << "Range: " << detection.range << " " << "Bearing: " << detection.bearing << " " << "x: " << detection.x << " " << "y: " << detection.y
        << std::endl;
    }
    return 0;
}
