#include <ctime>
#include <cstdlib>

#include "lane.h"
#include "traffic_light.h"
#include "vehicle.h"
#include "controller.h"

namespace simulation {

Lane::Lane(int speed_limit, int length):
    speed_limit_{speed_limit}, length_{length}
{}

void Lane::set_controller(Controller* controller) {
    controller_ = controller;
}

int Lane::vehicle_count() {
    return total_count_;
}

bool Lane::enough_room(Vehicle& vehicle) {
    return filled_length_ + vehicle.size() <= length_;
}

Vehicle Lane::pop_vehicle() {
    return vehicles_.dequeue();
}

const Vehicle& Lane::first_vehicle() const {
    return vehicles_.back();
}

InputLane::InputLane(int speed_limit, int length,
                     int spawn_delay, int spawn_variation,
                     Lane* out1, Lane* out2, Lane* out3,
                     float prob1, float prob2, float prob3):
    Lane{speed_limit, length}, 
    spawn_delay_{spawn_delay}, 
    spawn_variation_{spawn_variation},
    probabilities_{prob1, prob2, prob3},
    destinations_{out1, out2, out3}
{
    spawn_vehicle();
}

void InputLane::add_vehicle(Vehicle vehicle) {
    auto travel_time = 3.6 * length_/speed_limit_;
    controller_->schedule_arrival(this, static_cast<int>(travel_time));
    
    srand (static_cast <unsigned> (time(0)));
    auto x = static_cast<float> (rand() / static_cast<float> (RAND_MAX));

    if (x < probabilities_[0]) {
        vehicle.set_destination(destinations_[0]);
    } else if (x < probabilities_[1]) {
        vehicle.set_destination(destinations_[1]);
    } else
        vehicle.set_destination(destinations_[2]);

    vehicles_.enqueue(vehicle);
}

void InputLane::spawn_vehicle() {
    srand(static_cast <unsigned> (time(0)));
    auto max = static_cast<int> (RAND_MAX);
    auto r = static_cast<int> (rand() / max);

    auto vehicle = Vehicle{2 + 4 * r};
    add_vehicle(vehicle);

    r = static_cast<int> (rand() / max);

    auto time_until = spawn_delay_ + 2 * r * spawn_variation_;
    controller_->schedule_spawn(this, time_until);
}

void InputLane::process_arrival() {
    auto vehicle = pop_vehicle();
    auto lane = vehicle.destination();
    if (lane->enough_room(vehicle) and trafficlight_->is_open(this)) {
        lane->add_vehicle(vehicle);
    } else {
        auto time_until =  trafficlight_->time_until_reopen(this);
        controller_->schedule_arrival(this, time_until);
    }
}

ConnectionLane::ConnectionLane(int speed_limit, int length,
                               Lane* out1, Lane* out2, Lane* out3,
                               float a, float b, float c):
    Lane{speed_limit, length},
    probabilities_{a, b, c},
    destinations_{out1, out2, out3}
{}

void ConnectionLane::add_vehicle(Vehicle vehicle) {
    auto travel_time = 3.6 * length_/speed_limit_;
    controller_->schedule_arrival(this, static_cast<int>(travel_time));

    srand (static_cast <unsigned> (time(0)));
    auto x = static_cast<float> (rand() / static_cast<float> (RAND_MAX));

    if (x < probabilities_[0]) {
        vehicle.set_destination(destinations_[0]);
    } else if (x < probabilities_[1]) {
        vehicle.set_destination(destinations_[1]);
    } else
        vehicle.set_destination(destinations_[2]);

    vehicles_.enqueue(vehicle);
}

void ConnectionLane::process_arrival() {
    auto vehicle = pop_vehicle();
    auto lane = vehicle.destination();
    if (lane->enough_room(vehicle) and trafficlight_->is_open(this)) {
        lane->add_vehicle(vehicle);
    } else {
        auto time_until =  trafficlight_->time_until_reopen(this);
        controller_->schedule_arrival(this, time_until);
    }
}

OutputLane::OutputLane(int speed_limit, int length):
                       Lane{speed_limit, length}
{}

void OutputLane::add_vehicle(Vehicle vehicle) {
    auto travel_time = 3.6 * length_/speed_limit_;
    controller_->schedule_arrival(this, static_cast<int>(travel_time));
    vehicles_.enqueue(vehicle);
}

void OutputLane::process_arrival() {
    pop_vehicle();
}

}
