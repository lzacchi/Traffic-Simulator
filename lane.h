#ifndef STRUCTURES_LANE_H
#define STRUCTURES_LANE_H

#include<cstdint>
#include<stdexcept>

#include "linked_queue.h"
#include "linked_list.h"

namespace structures {

template<typename T>


class Lane {
public:
    Lane() = default;

    ~Lane(){}

    /*! Lane Change
    *
    * Vehicle arrives at semaphore and decides which lane it will change to */
    void lane_change() {

    }

    void insert_vehicle() {
    }

    int speed_limit() {
        return speed_limit_;
    }

    std::size_t size() const {
        return size_;
    }

protected:
    structures::LinkedList<int> list{};  //Probably not int. It's temporary.

private:
    int speed_limit_;
    std::size_t size_;
    structures::LinkedList<Lane> lanes{};  // Possible destinations
};

}  // namespace structures

#endif
