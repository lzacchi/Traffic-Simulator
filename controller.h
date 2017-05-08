#ifndef SIMULATION_CONTROLLER_H
#define SIMULATION_CONTROLLER_H

#include "event.h"
#include "linked_list.h"

namespace simulation {

class Controller {
public:
    Controller() = default;

    void schedule(Event event) {
        queue_.insert_sorted(event);
    }

    void run(unsigned duration) {
        for (auto i = 0u; i < duration; ++i) {
            auto next = queue_.at(queue_.size() - 1);
            if (next.deadline() <= clock_) {
                next.process();
            }
            ++clock_;
        }
    }

private:
    unsigned clock_{0u};
    structures::LinkedList<Event> queue_;
};

}

#endif
