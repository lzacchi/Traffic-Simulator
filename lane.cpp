#include "lane.h"

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

void Lane::add_vehicle(Vehicle vehicle) {
    vehicles_.enqueue(vehicle);
}

Vehicle Lane::pop_vehicle() {
    return vehicles_.dequeue();
}

const Vehicle& Lane::first_vehicle() const{
    return vehicles_.back();
}

InputLane::InputLane(Lane* out1, Lane* out2, Lane* out3,
                     int spawn_delay, int spawn_variation,
                     int speed_limit, int length):
    Lane{speed_limit, length}, outgoing_{out1, out2, out3},
    spawn_delay_{spawn_delay}, spawn_variation_{spawn_variation}
{}

void InputLane::spawn_vehicle() {
    auto vehicle = Vehicle{};
}

ConnectionLane::ConnectionLane(Lane* out1, Lane* out2, Lane* out3,
                               int speed_limit, int length):
    Lane{speed_limit, length}, outgoing_{out1, out2, out3}
{}

OutputLane::OutputLane(int speed_limit, int length):
                       Lane{speed_limit, length}
{}

}
