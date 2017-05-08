#ifndef SIMULATION_VEHICLE_H
#define SIMULATION_VEHICLE_H

namespace simulation {

class Vehicle {
public:
    Vehicle() = delete;

    Vehicle(int length):
    length_{length}
    {}

    int size() {
        return length_ + 3;
    }

private:
    int length_;
};

}

#endif
