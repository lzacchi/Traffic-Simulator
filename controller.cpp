#include <iostream>
#include "controller.h"
#include "event.h"

namespace simulation {

unsigned Controller::current_time() {
    return clock_;
}

void Controller::schedule(Event event) {
    queue_.insert_sorted(event);
}

void Controller::add_lane(Lane* lane) {
    lane->set_controller(this);
}

void Controller::add_traffic_light(TrafficLight* light) {
    light->set_controller(this);
}

void Controller::schedule_traffic_light(TrafficLight* light, int time_until) {
    schedule(TrafficLightEvent{light, clock_ + time_until});
}

void Controller::schedule_spawn(InputLane* lane, int time_until) {
    schedule(SpawnEvent{lane, clock_ + time_until});
}

void Controller::schedule_arrival(Lane* lane, int time_until) {
    schedule(ArrivalEvent{lane, clock_ + time_until});
}

void Controller::run(unsigned duration) {
    for (auto i = 0u; i < duration; ++i) {
        if (queue_.empty()) {
            continue;
        }
        while (queue_.back().deadline() <= clock_) {
            auto event = queue_.pop_back();
            std::cout << event.description() << '\n';
            event.process();
        }
        ++clock_;
    }
}

}
