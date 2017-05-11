#ifndef SIMULATION_LANE_H
#define SIMULATION_LANE_H

#include "linked_queue.h"

namespace simulation {

class Controller;
class Vehicle;
class TrafficLight;
class Lane {
public:
    Lane(int speed_limit, int length);

    void set_controller(Controller* controller);

    int vehicle_count();

    bool enough_room(Vehicle& vehicle);

    virtual void add_vehicle(Vehicle vehicle) = 0;

    virtual void process_arrival() = 0;

    Vehicle pop_vehicle();

    const Vehicle& first_vehicle() const;

protected:
    int speed_limit_;
    int length_;
    int filled_length_;
    int total_count_;
    Controller* controller_;
    structures::LinkedQueue<Vehicle> vehicles_;
    TrafficLight* trafficlight_;
};

class InputLane : public Lane {
public:
    InputLane(int speed_limit, int length,
              int spawn_delay, int spawn_variation,
              Lane* out1, Lane* out2, Lane* out3,
              float prob1, float prob2, float prob3);

    void spawn_vehicle();

    virtual void add_vehicle(Vehicle vehicle) override;

    void process_arrival() override;

private:
    int const spawn_delay_;
    int spawn_variation_;
    float probabilities_[3];
    Lane* destinations_[3];
};

class ConnectionLane : public Lane {
public:
    ConnectionLane(int speed_limit, int length, 
                   Lane* out1, Lane* out2, Lane* out3,
                   float prob1, float prob2, float prob3);

    virtual void add_vehicle(Vehicle vehicle) override;

    void process_arrival() override;

private:
    float probabilities_[3];
    Lane* destinations_[3];
};

class OutputLane : public Lane {
public:
    OutputLane(int speed_limit, int length);

    virtual void add_vehicle(Vehicle vehicle) override;

    void process_arrival() override;
};

}

#endif
