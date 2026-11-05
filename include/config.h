#ifndef CONFIG_H
#define CONFIG_H

struct Config { 
    double dt = 1.0;
    int num_scans = 120;
    int seed = 42;
    double max_range = 20000.0;
    double range_noise = 50.0;
    double bearing_noise = 0.00873;
    double prob_detect = 0.9;
    double clutter_mean = 3.0;
    double accel_noise = 1.0;
    double init_velocity_std = 300.0;
    double gate_threshold = 9.21;
    int confirm_hits = 3;
    int confirm_window = 5;
    int max_misses = 3;
};

#endif