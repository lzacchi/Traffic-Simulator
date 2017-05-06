#ifndef SIMULATION_LANE_H
#define SIMULATION_LANE_H

#include <cstdint>
#include <stdlib.h>
#include <stdexcept>
#include <time.h>

#include "linked_queue.h"
#include "linked_list.h"
#include "vehicle.h"

namespace simulation {

class Lane {
public:
    Lane() = default;

    ~Lane() {
        list.clear();
    }

    /*      Lane Change
    *
    *           Removes vehicle from the lane (pop) and inserts it in one of the
    *           possible destinations */
    void lane_change() {
        list.pop_back();
        //pick one of the destinations and 'call push_front()'
        
    }

    void insert_vehicle() {
        auto new_vehicle = new Vehicle{size()};  // generates [-Wnarrowing]
        list.push_front(new_vehicle->size());  // not sure if this is done correctly.
    }

    int speed_limit() {
        return speed_limit_;
    }

    std::size_t size() const {
        return size_;
    }

protected:
    structures::LinkedList<int> list{};  //Probably not int. It's temporary.
    structures::LinkedList<Lane> destinations{};

private:
    int speed_limit_;
    std::size_t size_;
    Vehicle *vehicle;
};

}  // namespace simulation

#endif
