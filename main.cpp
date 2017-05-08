#include <iostream>

#include "controller.h"
#include "lane.h"
#include "traffic_light.h"

using namespace simulation;

int main() {

    auto n1_north = OutputLane{};
    auto n2_north = OutputLane{};
    auto s1_south = OutputLane{};
    auto s2_south = OutputLane{};
    auto w_west = OutputLane{};
    auto e_east = OutputLane{};

    auto m_east = ConnectionLane(&n2_north, &e_east, &s2_south);
    auto m_west = ConnectionLane(&n1_north, &w_west, &s1_south);

    auto n1_south = InputLane(&w_west, &s1_south, &m_east);
    auto n2_south = InputLane(&m_west, &s2_south, &e_east);

    auto s1_north = InputLane(&w_west, &n1_north, &m_east);
    auto s2_north = InputLane(&m_west, &n2_north, &e_east);

    auto w_east = InputLane(&n1_north, &m_east, &s1_south);
    auto e_west = InputLane(&n2_north, &m_west, &s2_south);

    auto simulation = Controller();

    auto L1 = TrafficLight(&n1_south, &m_west, &s1_north, &w_east,
                           20, 30, 10, 30, &simulation);
    auto L2 = TrafficLight(&n2_south, &e_west, &s2_north, &m_east,
                           20, 30, 10, 30, &simulation);

}
