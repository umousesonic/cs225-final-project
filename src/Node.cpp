#include "Node.h"

Node::Node() {
    latitude_ = 0;
    longitude_ = 0;
    id_ = "XXX";
}

Node::Node(long latitude, long longitude, string id) {
    latitude_ = latitude;
    longitude_ = longitude;
    id_ = id;
}

long Node::getLatitude() {
    return latitude_;
}

long Node::getLongitude() {
    return longitude_;
}

string Node::getId() {
    return id_;
}


