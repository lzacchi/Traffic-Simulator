#ifndef SIMULATION_LANE_H
#define SIMULATION_LANE_H

#include "linked_queue.h"
#include "vehicle.h"
#include "controller.h"

namespace simulation {

class Lane {
public:
    Lane() = delete;

protected:
    int speed_limit_;
    int length;
    structures::LinkedQueue<Vehicle*> vehicles;
    Controller* controller_;
};

class InputLane : Lane {
public:
    InputLane(Lane* out1, Lane* out2, Lane* out3);

private:
    Lane* outgoing[3];
};

class ConnectionLane : Lane {
public:
    ConnectionLane(Lane* out1, Lane* out2, Lane* out3);

private:
    Lane* outgoing[3];
};

class OutputLane : Lane {
public:
    OutputLane() = default;
};

}

#endif
