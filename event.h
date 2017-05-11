#ifndef SIMULATION_EVENT_H
#define SIMULATION_EVENT_H

#include <string>

#include "traffic_light.h"
#include "lane.h"
#include "vehicle.h"

namespace simulation {

class Event {
public:
    Event(unsigned deadline):
        deadline_{deadline}
    {}

    bool operator<(Event other) {
        return deadline_ < other.deadline();
    }

    unsigned deadline() {
        return deadline_;
    }

    void process() {
        return;
    }

    std::string description() {
        return "Event";
    }

protected:
    unsigned deadline_;
};

class TrafficLightEvent : public Event {
public:
    TrafficLightEvent(TrafficLight* target, unsigned deadline):
        Event{deadline}, target_{target}
    {}

    void process() {
        target_->cycle();
    }

    std::string description() {
        return "TrafficLightEvent";
    }

private:
    TrafficLight* target_;
};

class ArrivalEvent : public Event {
public:
    ArrivalEvent(Lane* target, unsigned deadline):
        Event{deadline}, target_{target}
    {}

    void process() {
        target_->process_arrival();
    }

    std::string description() {
        return "ArrivalEvent";
    }

private:
    Lane* target_;
};

class SpawnEvent : public Event {
public:
    SpawnEvent(InputLane* target, unsigned deadline):
        Event{deadline}, target_{target}
    {}

    void process() {
        target_->spawn_vehicle();
    }

    std::string description() {
        return "SpawnEvent";
    }

private:
    InputLane* target_;
};

}

#endif
