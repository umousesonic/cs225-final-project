#include "Node.h"

Node::Node() {
    latitude_ = 0;
    longitude_ = 0;
    id_ = "XXX";
}

Node::Node(double latitude, double longitude, string id) {
    latitude_ = latitude;
    longitude_ = longitude;
    id_ = id;
}

double Node::getLatitude() {
    return latitude_;
}

double Node::getLongitude() {
    return longitude_;
}

string Node::getId() {
    return id_;
}

void Node::addEdge(Edge* input) {
    edges_.push_back(input);
}


