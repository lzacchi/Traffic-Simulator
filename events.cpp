#include <cstdlib>

#include "lane.h"
#include "semaphore.h"

namespace simulation {

class Events {
public:
    Events() = default;

    ~Events() {}

    void generate_vehicle() {
        lane->insert_vehicle();
    }

    void cycle_semaphore() {
        sem->cycle();
    }

    //vehicle arrives at intersection()

    void lane_change();

protected:
    Lane *lane;
    Semaphore *sem;

private:
    //
};

}  // namespace simulation
