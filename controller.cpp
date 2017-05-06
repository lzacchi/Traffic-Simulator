#include <cstdlib>

#include "lane.h"
#include "semaphore.h"




namespace simulation {

class Controller {
public:
    Controller() = default;

    ~Controller() {}

protected:
    structures::LinkedList<Semaphore> semaphores{};
    structures::LinkedList<Lane> lanes{};

private:

};

}
