#ifndef STRUCTURES_LANE_H
#define STRUCTURES_LANE_H

#include<cstdint>
#include<stdexcept>

#include "linked_queue.h"

namespace structures {

template<typename T>


class Lane {
public:
    Lane() = default;

    ~Lane(){}


    int speed_limit() {
        return speed_limit_;
    }

    int size() {
        return size_;
    }

protected:
    structures::LinkedQueue<int> queue{};

private:
    int speed_limit_, size_;

};

}  // namespace structures

#endif
