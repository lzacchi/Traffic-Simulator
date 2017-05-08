#include "controller.h"

namespace simulation {

    void Controller::schedule(Event event) {
        queue_.insert_sorted(event);
    }

    void Controller::run(unsigned duration) {
        for (auto i = 0u; i < duration; ++i) {
            auto next = queue_.at(queue_.size() - 1);
            if (next.deadline() <= clock_) {
                next.process();
            }
            ++clock_;
        }
    }

}
