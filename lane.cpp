#include <ctime>
#include <cstdlib>

#include "lane.h"  // STUPID LITTLE ERROR I DON'T KNOW WHAT TO DO WITH

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

void Lane::add_vehicle(Vehicle& vehicle) {

    srand (static_cast <unsigned> (time(0)));

    auto x = static_cast<float> (rand() / static_cast<float> (RAND_MAX));

    if (x < probabilities[0]) {
        vehicle.set_destination(destinations_[0]);
    } 

    else if (x < probabilities[1]) {
        vehicle.set_destination(destinations_[1]);
    }

    else
        vehicle.set_destination(destinations_[2]);

    vehicles_.enqueue(vehicle);
}

void Lane::process_arrival(Vehicle& vehicle) {
    if (trafficlight_->is_open(this) && vehicle.destination()->enough_room(vehicle)) {
        pop_vehicle();
        vehicle.destination()->add_vehicle(vehicle);
    }
}

Vehicle Lane::pop_vehicle() {
    return vehicles_.dequeue();
}

const Vehicle& Lane::first_vehicle() const {
    return vehicles_.back();
}

InputLane::InputLane(Lane* out1, Lane* out2, Lane* out3,
                     int spawn_delay, int spawn_variation,
                     int speed_limit, int length,
                     float a, float b, float c):
    Lane{speed_limit, length}, 
    // outgoing_{out1, out2, out3},
    spawn_delay_{spawn_delay}, 
    spawn_variation_{spawn_variation},
    probabilities_{a,b,c},
    destinations_{out1, out2, out3}
{}

void InputLane::spawn_vehicle() {
    auto v_length_ = vehicle->length();
    auto vehicle = Vehicle{v_length_,};
    add_vehicle(vehicle);
}

ConnectionLane::ConnectionLane(Lane* out1, Lane* out2, Lane* out3,
                               int speed_limit, int length,
                               float a, float b, float c):
    Lane{speed_limit, length}, 
    // outgoing_{out1, out2, out3},
    probabilities_{a,b,c},
    destinations_{out1,out2,out3}
{}

OutputLane::OutputLane(int speed_limit, int length):
                       Lane{speed_limit, length}
{}

}
