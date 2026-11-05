#ifndef RADAR_H
#define RADAR_H

#include <vector>
#include "config.h"
#include "detection.h"
#include "world.h"


class Radar {
public:
    Radar(double x, double y, const Config& config);
    std::vector<Detection> scan(const World& world, double time);

private:
    double x_;
    double y_;
    Config config_;
};

#endif