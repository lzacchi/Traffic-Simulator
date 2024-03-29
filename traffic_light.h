#ifndef SIMULATION_TRAFFIC_LIGHT_H
#define SIMULATION_TRAFFIC_LIGHT_H

namespace simulation {

class Lane;
class Controller;
class TrafficLight {
public:
    TrafficLight(Lane* in1, Lane* in2, Lane* in3, Lane* in4,
                 int duration1, int duration2, int duration3, int duration4);

    void set_controller(Controller* controller);

    bool is_open(Lane* lane);

    int time_until_reopen(Lane* lane);

    void cycle();

private:
    Controller* controller_;
    Lane* incoming_[4];
    int current_open_;
    int last_change_;
    int duration_[4];
};

}

#endif
