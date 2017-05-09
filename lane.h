#ifndef SIMULATION_LANE_H
#define SIMULATION_LANE_H

#include "vehicle.h"
#include "linked_queue.h"

namespace simulation {


class Controller;

class Lane {
public:
    Lane(int speed_limit, int length);

    void set_controller(Controller* controller);

    int vehicle_count();

    bool enough_room(Vehicle& vehicle);

    void add_vehicle(Vehicle vehicle);

    Vehicle pop_vehicle();

    const Vehicle& first_vehicle() const;

protected:
    int speed_limit_;
    int length_;
    int filled_length_;
    int total_count_;
    structures::LinkedQueue<Vehicle> vehicles_;
    Controller* controller_;
};

class InputLane : public Lane {
public:
    InputLane(Lane* out1, Lane* out2, Lane* out3,
              int spawn_delay, int spawn_variation,
              int speed_limit, int length);

    void spawn_vehicle();

private:
    Lane* outgoing_[3];
    int spawn_delay_;
    int spawn_variation_;
    Vehicle* vehicle;
};

class ConnectionLane : public Lane {
public:
    ConnectionLane(Lane* out1, Lane* out2, Lane* out3,
                   int speed_limit, int length);

private:
    Lane* outgoing_[3];
};

class OutputLane : public Lane {
public:
    OutputLane(int speed_limit, int length);
};

}

#endif
