#include "world.h"

const std::vector<Target>& World::getTargets() const {
    return targets_;
}
 void World::step(double dt) {
    for(Target& target : targets_) {
        target.step(dt);
        }
    }
void World::addTarget(const Target& target) { 
    targets_.push_back(target);
    }