#ifndef SIMULATION_VEHICLE_H
#define SIMULATION_VEHICLE_H

namespace simulation {

class Vehicle {
public:
    Vehicle(unsigned short length):
    length_{length};
    {}

    unsigned short size() {
        return length_ + 3;
    }

private:
    unsigned short length_;
};

}

#endif
