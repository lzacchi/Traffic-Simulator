#include <iostream>

#include "controller.h"
#include "lane.h"
#include "traffic_light.h"

using namespace simulation;

int main() {

    auto sim = Controller{};

    auto n1_north = OutputLane{60, 500};
    auto n2_north = OutputLane{40, 500};
    auto s1_south = OutputLane{60, 500};
    auto s2_south = OutputLane{40, 500};
    auto w_west = OutputLane{80, 2000};
    auto e_east = OutputLane{30, 400};

    auto m_east = ConnectionLane{60, 300, &n2_north, &e_east, &s2_south, 5.0, 3.2, 1.2};
    auto m_west = ConnectionLane{60, 300, &n1_north, &w_west, &s1_south, 5.0, 3.2, 1.2};

    auto n1_south = InputLane{60, 500, 20, 5, &w_west, &s1_south, &m_east, 5.0, 3.2, 1.2};
    auto n2_south = InputLane{40, 500, 20, 5, &m_west, &s2_south, &e_east, 5.0, 3.2, 1.2};

    auto s1_north = InputLane{60, 500, 30, 7, &w_west, &n1_north, &m_east, 5.0, 3.2, 1.2};
    auto s2_north = InputLane{40, 500, 60, 15, &m_west, &n2_north, &e_east, 5.0, 3.2, 1.2};

    auto w_east = InputLane{80, 2000, 10, 2, &n1_north, &m_east, &s1_south, 5.0, 3.2, 1.2};
    auto e_west = InputLane{30, 400, 10, 2, &n2_north, &m_west, &s2_south, 5.0, 3.2, 1.2};

    auto light1 = TrafficLight{&n1_south, &m_west, &s1_north, &w_east, 10, 10, 10, 10};
    auto light2 = TrafficLight{&n2_south, &e_west, &s2_north, &m_east, 10, 10, 10, 10};


    sim.add_lane(&n1_north);
    sim.add_lane(&n2_north);
    sim.add_lane(&s1_south);
    sim.add_lane(&s2_south);
    sim.add_lane(&w_west);
    sim.add_lane(&e_east);
    sim.add_lane(&m_east);
    sim.add_lane(&m_west);
    sim.add_lane(&n1_south);
    sim.add_lane(&n2_south);
    sim.add_lane(&s1_north);
    sim.add_lane(&s2_north);
    sim.add_lane(&w_east);
    sim.add_lane(&e_west);
    sim.add_traffic_light(&light1);
    sim.add_traffic_light(&light2);

    sim.run(1000000);
    std::cout << m_west.vehicle_count() << '\n';
    std::cout << m_east.vehicle_count() << '\n';

}
