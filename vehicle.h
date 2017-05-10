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

    int length() {
        srand (static_cast <unsigned> (time(0)));
        length_ = static_cast<int> (rand() / static_cast<int> (RAND_MAX));
        return length_;
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
