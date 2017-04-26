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

protected:
    structures::LinkedList<int> list{};

private:
};

}  // namespace structures

#endif
