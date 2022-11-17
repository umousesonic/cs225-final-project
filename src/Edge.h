#pragma once

#include "Flight.h"

#include <iostream>
#include <vector>
#include <string>

class Edge {
    public:
        Edge();
        void addFlight(Flight* flight);
        Flight* getFlight(size_t index);
        size_t countFlights();

    private:
        vector<Flight*> flights_;
};