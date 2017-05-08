#ifndef SIMULATION_CONTROLLER_H
#define SIMULATION_CONTROLLER_H

#include "lane.h"
#include "traffic_light.h"
#include "event.h"
#include "linked_list.h"

namespace simulation {

class Controller {
public:
    Controller() = default;

    void schedule(Event event);

    void add_lane(Lane* lane);

    void add_traffic_light(TrafficLight* light);

    void schedule_traffic_light(TrafficLight* light, int time_until);

    void schedule_spawn(Lane* lane, int time_until);

    void schedule_arrival(Lane* lane, int time_until);

    void run(unsigned duration);

private:
    unsigned clock_{0u};
    structures::LinkedList<Event> queue_;
};

}

#endif
