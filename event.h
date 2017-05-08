#ifndef SIMULATION_EVENT_H
#define SIMULATION_EVENT_H

#include "traffic_light.h"
#include "lane.h"
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

class TrafficLightEvent : public Event {
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

class ArrivalEvent : public Event {
public:
    ArrivalEvent(unsigned deadline, Lane* target):
        Event{deadline}, target_{target}
    {}

    void process() {
        // ...
    }

private:
    Lane* target_;
};

class SpawnEvent : public Event {
public:
    SpawnEvent(unsigned deadline, InputLane* target):
        Event{deadline}, target_{target}
    {}

    void process() {
        target_->spawn_vehicle();
    }

private:
    Lane* target_;
};

}

#endif
