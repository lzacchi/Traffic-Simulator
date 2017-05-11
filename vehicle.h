#ifndef SIMULATION_VEHICLE_H
#define SIMULATION_VEHICLE_H

#include <cstdlib>
#include <ctime>
namespace simulation {

class Lane;
class Vehicle {
public:
    Vehicle() = delete;

    Vehicle(int length):
    length_{length}
    {}

    int size() {
        return length_ + 3;
    }

    Lane* destination() {
        return destination_;
    }

    void set_destination(Lane* destination) {
        destination_ = destination;
    }

private:
    int length_;
    Lane* destination_;
};

}

#endif
