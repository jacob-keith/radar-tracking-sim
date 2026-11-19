#include "radar.h"
#include <cmath>

Radar::Radar(double x, double y, const Config& config)
    : x_(x), y_(y), config_(config), rng_(config.seed){}

std::vector<Detection> Radar::scan(const World& world, double time) {
    std::vector<Detection> detections;
    std::bernoulli_distribution detected(config_.prob_detect);
    std::normal_distribution<double> range_error(0.0, config_.range_noise);
    std::normal_distribution<double> bearing_error(0.0, config_.bearing_noise);

    for (const Target& target : world.getTargets()) {
        double dx = target.getX() - x_;
        double dy = target.getY() - y_;
        double range = std::sqrt(dx * dx + dy * dy);

        if (range > config_.max_range) {
            continue;
        }
        if (!detected(rng_)) {
            continue;
        }

        double bearing = std::atan2(dy, dx);

        Detection detection;
        detection.time = time;
        double noisy_range = range + range_error(rng_);
        double noisy_bearing = bearing + bearing_error(rng_);
        detection.range = noisy_range;
        detection.bearing = noisy_bearing;
        detection.x = x_ + noisy_range * std::cos(noisy_bearing);
        detection.y = y_ + noisy_range * std::sin(noisy_bearing);
        detections.push_back(detection);
    }

    return detections;
}
