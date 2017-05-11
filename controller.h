#ifndef SIMULATION_CONTROLLER_H
#define SIMULATION_CONTROLLER_H

#include "linked_list.h"

#include <vector>
#include <stdexcept>

namespace simulation {

class Lane;
class InputLane;
class TrafficLight;
class Event;
class Controller {
public:

    Controller() = default;

    unsigned current_time();

    void schedule(Event event);

    void add_lane(Lane* lane);

    void add_traffic_light(TrafficLight* light);

    void schedule_traffic_light(TrafficLight* light, int time_until);

    void schedule_spawn(InputLane* lane, int time_until);

    void schedule_arrival(Lane* lane, int time_until);

    void run(unsigned duration);

private:
    unsigned clock_{0u};
    structures::LinkedList<Event> queue_;
};

}

#endif
