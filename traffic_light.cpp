#include "traffic_light.h"

namespace simulation {

TrafficLight::TrafficLight(Lane* in1, Lane* in2, Lane* in3, Lane* in4,
                           int duration1, int duration2, int duration3, int duration4):
    incoming_{in1, in2, in3, in4}, current_open_{4},
    duration_{duration1, duration2, duration3, duration4}
    {
        cycle();
    }

void TrafficLight::set_controller(Controller* controller) {
    controller_ = controller;
}

bool TrafficLight::is_open(Lane* lane) {
    if (current_open_ > 3) {
        return false;
    } else {
        return lane == incoming_[current_open_];
    }
}

void TrafficLight::cycle() {
    current_open_ = (current_open_ + 1) % 5;
    controller_->schedule_traffic_light(this, duration_[current_open_]);
}

}
