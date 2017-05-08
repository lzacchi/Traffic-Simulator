#ifndef SIMULATION_LANE_H
#define SIMULATION_LANE_H

#include "controller.h"
#include "vehicle.h"
#include "linked_queue.h"

namespace simulation {

class Lane {
public:
    Lane(int speed_limit, int length, Controller* controller):
        speed_limit_{speed_limit}, length_{length}, controller_{controller}
    {}

    int vehicle_count() {
        return count_;
    }

protected:
    int speed_limit_;
    int length_;
    int count_;
    structures::LinkedQueue<Vehicle*> vehicles;
    Controller* controller_;
};

class InputLane : public Lane {
public:
    InputLane(Lane* out1, Lane* out2, Lane* out3,
              int spawn_delay, int spawn_variation,
              int speed_limit, int length, Controller* controller):
        Lane{speed_limit, length, controller},
        outgoing_{out1, out2, out3},
        spawn_delay_{spawn_delay}, spawn_variation_{spawn_variation}
    {}

private:
    Lane* outgoing_[3];
    int spawn_delay_;
    int spawn_variation_;
};

class ConnectionLane : public Lane {
public:
    ConnectionLane(Lane* out1, Lane* out2, Lane* out3,
                   int speed_limit, int length, Controller* controller):

        Lane{speed_limit, length, controller}, outgoing_{out1, out2, out3}
    {}

private:
    Lane* outgoing_[3];
};

class OutputLane : public Lane {
public:
    OutputLane() = default;
};

}

#endif
