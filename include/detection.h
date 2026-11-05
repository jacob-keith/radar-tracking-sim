#ifndef DETECTION_H
#define DETECTION_H

struct Detection {
    double time = 0.0;
    double range= 0.0;
    double bearing = 0.0;
    double x = 0.0;
    double y = 0.0;
    bool is_clutter = false;

};

#endif