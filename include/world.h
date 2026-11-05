#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "target.h"

class World {
public:
    void addTarget(const Target& target);
    void step(double dt);
    const std::vector<Target>& getTargets() const;

private:
    std::vector<Target> targets_;
};

#endif