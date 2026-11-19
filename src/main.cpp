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

    int count = 0;
    for (int i = 0; i < 20; i++) {
        std::vector<Detection> detections = radar.scan(world, 0.0);
        count += detections.size();
    }

    std::cout << "Detections in 20 scans: " << count << std::endl;

    return 0;
}
