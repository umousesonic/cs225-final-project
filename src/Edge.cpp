#include "Edge.h"

Edge::Edge() {
}

void Edge::addFlight(Flight* flight) {
    flights_.push_back(flight);
}

Flight* Edge::getFlight(size_t index) {
    return flights_.at(index);
}

size_t Edge::countFlights() {
    return flights_.size();
}

