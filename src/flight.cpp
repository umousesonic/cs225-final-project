
#include "Flight.h"

Flight::Flight(string id, string from, string to) {
    id_ = id;
    from_ = from;
    to_ = to;
}

string Flight::getId() {
    return id_;
}

string Flight::getFrom() {
    return from_;
}

string Flight::getTo() {
    return to_;
}
//Note: "flight.cpp" should be "Flight.cpp"
