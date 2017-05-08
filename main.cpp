#include <iostream>

#include "lane.h"
#include "traffic_light.h"
#include "controller.h"

using namespace simulation;

int main() {

    auto sim = Controller{};

    auto n1_north = OutputLane{60, 500, &sim};
    auto n2_north = OutputLane{40, 500, &sim};
    auto s1_south = OutputLane{60, 500, &sim};
    auto s2_south = OutputLane{40, 500, &sim};
    auto w_west = OutputLane{80, 2000, &sim};
    auto e_east = OutputLane{30, 400, &sim};

    auto m_east = ConnectionLane{&n2_north, &e_east, &s2_south,
                                 60, 300, &sim};
    auto m_west = ConnectionLane{&n1_north, &w_west, &s1_south,
                                 60, 300, &sim};

    auto n1_south = InputLane{&w_west, &s1_south, &m_east,
                              20, 5, 60, 500, &sim};
    auto n2_south = InputLane{&m_west, &s2_south, &e_east,
                              20, 5, 40, 500, &sim};

    auto s1_north = InputLane{&w_west, &n1_north, &m_east,
                              30, 7, 60, 500, &sim};
    auto s2_north = InputLane{&m_west, &n2_north, &e_east,
                              60, 15, 40, 500, &sim};

    auto w_east = InputLane{&n1_north, &m_east, &s1_south,
                            10, 2, 80, 2000, &sim};
    auto e_west = InputLane{&n2_north, &m_west, &s2_south,
                            10, 2, 30 ,400, &sim};

    auto light1 = TrafficLight{&n1_south, &m_west, &s1_north, &w_east,
                               20, 30, 10, 30, &sim};
    auto light2 = TrafficLight{&n2_south, &e_west, &s2_north, &m_east,
                               20, 30, 10, 30, &sim};

    sim.run(60);
    std::cout << m_west.vehicle_count() << '\n';
    std::cout << m_east.vehicle_count() << '\n';
}
