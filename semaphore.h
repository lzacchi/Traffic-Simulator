#ifndef STRUCTURES_SEMAPHORE_H
#define STRUCTURES_SEMAPHORE_H


#include<cstdint>
#include<stdexcept>

#include "linked_list.h"
#include "lane.h"

namespace structures {

class Semaphore {
public:
    Semaphore() = default;

    ~Semaphore(){};

    /**
    *@brief     Coordinates the traffic lights at the intersection
    *
    *           i_ represents the lane for which the lights are green
    *           if i_ == 4, the lights are red for every lane.
    *
    */
    void cycle() {
        i_ = (i_ + 1 % 5);
    }

    /**
    * @brief     Verifies which lane can advance
    *
    * @param    lane
    */
    bool check(Lane* lane) {
        if (i_ == 4) {
            return false;
        } else {
            return lane == incoming[i_];
        }
    }

    // void schedule(Controller* controller) {
    //
    // }



protected:
    structures::LinkedList<int> list{};

private:
    Lane* incoming[4];
    Lane* outgoing[4];
    int i_;
};

}  // namespace structures

#endif
