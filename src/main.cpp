#include <iostream>
#include "target.h"
#include "world.h"
#include "config.h"

int main() {
    Config config;

    std::cout << config.dt << " " << config.max_range << std::endl;

    Target target1(1, 0.0, 0.0, 10.0, 5.0);
    Target target2(2, 1000.0, 0.0, -20.0, 0.0);

    World world;
    world.addTarget(target1);
    world.addTarget(target2);

    for (int i = 0; i < 10; i++) {
        world.step(1.0);
    }
    for (const Target& target : world.getTargets()) {
        std::cout << "Target " << target.getId()
            << ": (" << target.getX() << ", " << target.getY() << ")"
            << std::endl; 
    }
return 0;
}
