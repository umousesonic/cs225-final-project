#include "Edge.h"

Edge::Edge() {
    
}

void Edge::addFlight(Flight* flight) {
    flights_.push_back(flight);
}