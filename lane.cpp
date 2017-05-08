#include "lane.h"

namespace simulation {

Lane::Lane(int speed_limit, int length):
    speed_limit_{speed_limit}, length_{length}
{}

void Lane::set_controller(Controller* controller) {
    controller_ = controller;
}

int Lane::vehicle_count() {
    return count_;
}

InputLane::InputLane(Lane* out1, Lane* out2, Lane* out3,
                     int spawn_delay, int spawn_variation,
                     int speed_limit, int length):
    Lane{speed_limit, length}, outgoing_{out1, out2, out3},
    spawn_delay_{spawn_delay}, spawn_variation_{spawn_variation}
{}

ConnectionLane::ConnectionLane(Lane* out1, Lane* out2, Lane* out3,
                               int speed_limit, int length):
    Lane{speed_limit, length}, outgoing_{out1, out2, out3}
{}

OutputLane::OutputLane(int speed_limit, int length):
                       Lane{speed_limit, length}
{}

}
