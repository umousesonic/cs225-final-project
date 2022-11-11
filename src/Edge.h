#pragma once

#include "Flight.h"

#include <iostream>
#include <vector>
#include <string>

class Edge {
    public:
        Edge();
        void addFlight(Flight* flight);

    private:
        vector<Flight*> flights_;
};
