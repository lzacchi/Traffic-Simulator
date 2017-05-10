#ifndef SIMULATION_LANE_H
#define SIMULATION_LANE_H

#include "vehicle.h"
#include "linked_queue.h"
#include "traffic_light.h"

namespace simulation {

class Controller;
// class TrafficLight;

class Lane {
public:
    Lane(int speed_limit, int length);

    void set_controller(Controller* controller);

    int vehicle_count();

    bool enough_room(Vehicle& vehicle);

    void add_vehicle(Vehicle& vehicle);

    void process_arrival(Vehicle& vehicle);

    Vehicle pop_vehicle();

    const Vehicle& first_vehicle() const;

protected:
    int speed_limit_;
    int length_;
    int filled_length_;
    int total_count_;
    float probabilities[3];
    structures::LinkedQueue<Vehicle> vehicles_;
    Controller* controller_;
    TrafficLight* trafficlight_;
    Lane* destinations_[3];
};

class InputLane : public Lane {
public:
    InputLane(Lane* out1, Lane* out2, Lane* out3,
              int spawn_delay, int spawn_variation,
              int speed_limit, int length, float a, float b, float c, Lane* x, Lane* y, Lane* z);

    void spawn_vehicle();

private:
    // Lane* outgoing_[3];
    int const spawn_delay_;
    int spawn_variation_;
    Vehicle* vehicle;
    float probabilities_[3];
    Lane* destinations_[3];
};

class ConnectionLane : public Lane {
public:
    ConnectionLane(Lane* out1, Lane* out2, Lane* out3,
                   int speed_limit, int length, float a, float b, float c, Lane* x, Lane* y, Lane* z);

private:
    //Lane* outgoing_[3];
    float probabilities_[3];
    Lane* destinations_[3];
};

class OutputLane : public Lane {
public:
    OutputLane(int speed_limit, int length);
};

}

#endif
