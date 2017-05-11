#include "traffic_light.h"
#include "lane.h"
#include "controller.h"

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

int TrafficLight::time_until_reopen(Lane* lane) {
    int lane_index = 0;
    for (auto i = 0u; i < 4; ++i) {
        if (incoming_[i] == lane) {
            lane_index = i;
            break;
        }
    }
    auto time_until = last_change_;
    for (auto i = current_open_; i != lane_index; i = (i + 1) % 4) {
        time_until += duration_[i];
    }
    return time_until;
}

void TrafficLight::cycle() {
    current_open_ = (current_open_ + 1) % 5;
    controller_->schedule_traffic_light(this, duration_[current_open_]);
    last_change_ = controller_->current_time();
}

}
