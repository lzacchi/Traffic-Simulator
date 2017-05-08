#ifndef SIMULATION_TRAFFIC_LIGHT_H
#define SIMULATION_TRAFFIC_LIGHT_H

#include "lane.h"
#include "controller.h"

namespace simulation {

class TrafficLight {
public:
    TrafficLight(Lane* in1, Lane* in2, Lane* in3, Lane* in4,
                 int duration1, int duration2, int duration3, int duration4,
                 Controller* controller):
        incoming_{in1, in2, in3, in4},
        duration_{duration1, duration2, duration3, duration4},
        open_{4}, controller_{controller}
        {
            cycle();
        }

    bool is_open(Lane* lane) {
        if (open_ > 3) {
            return false;
        } else {
            return lane == incoming_[open_];
        }
    }

    void cycle() {
        open_ = (open_ + 1) % 5;
        controller_.schedule_traffic_light(duration_[open_]);
    }

private:
    Lane* incoming_[4];
    int duration_[4];
    int open_;
    Controller* controller_;
};

}

#endif
