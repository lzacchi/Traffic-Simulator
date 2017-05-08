#ifndef SIMULATION_CONTROLLER_H
#define SIMULATION_CONTROLLER_H

#include "event.h"
#include "linked_list.h"

namespace simulation {

class Controller {
public:
    Controller() = default;

    void schedule(Event event);

    void run(unsigned duration);

private:
    unsigned clock_{0u};
    structures::LinkedList<Event> queue_;
};

}

#endif
