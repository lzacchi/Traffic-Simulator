#ifndef SIMULATION_EVENT_H
#define SIMULATION_EVENT_H

#include "traffic_light.h"
#include "vehicle.h"

namespace simulation {

class Event {
public:
    Event(unsigned deadline):
        deadline_{deadline}
    {}

    bool operator<(Event& other) {
        return deadline_ < other.deadline();
    }

    unsigned deadline() {
        return deadline_;
    }

    virtual void process();

protected:
    unsigned deadline_;
};

class TrafficLightEvent : Event {
public:
    TrafficLightEvent(unsigned deadline, TrafficLight* target):
        Event{deadline}, target_{target}
    {}

    void process() {
        target_->cycle();
    }

private:
    TrafficLight* target_;
};

class VehicleEvent : Event {
public:
    VehicleEvent(unsigned deadline, Lane* target):
        Event{deadline}, target_{target}
    {}

    void process() {
        target_->cycle();
    }

private:
    Lane* target_;
};

}

#endif
