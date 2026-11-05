#include "radar.h"
#include <cmath>

Radar::Radar(double x, double y, const Config& config)
    : x_(x), y_(y), config_(config) {}

std::vector<Detection> Radar::scan(const World& world, double time) {
    std::vector<Detection> detections;

    for (const Target& target : world.getTargets()) {
        double dx = target.getX() - x_;
        double dy = target.getY() - y_;
        double range = std::sqrt(dx * dx + dy * dy);

        if (range > config_.max_range) {
            continue;
        }

        double bearing = std::atan2(dy, dx);

        Detection detection;
        detection.time = time;
        detection.range = range;
        detection.bearing = bearing;
        detection.x = x_ + range * std::cos(bearing);
        detection.y = y_ + range * std::sin(bearing);

        detections.push_back(detection);
    }

    return detections;
}
