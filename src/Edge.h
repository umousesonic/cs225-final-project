#pragma once

#include "Flight.h"
#include "Node.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node;
class Edge {
    public:
        Edge();
        void addFlight(Flight* flight);
        Flight* getFlight(size_t index);
        size_t countFlights();
        string getFromID() {return from_id_; };
        string getToID() { return to_id_; };
        Node* getFromNode() { return from_node_; };
        Node* getToNode() { return to_node_; };
        void setFromID(string id) { from_id_ = id; };
        void setToID(string id) { to_id_ = id; };
        void setFromNode(Node* n) { from_node_ = n; };
        void setToNode(Node* n) { to_node_ = n; };

    private:
        vector<Flight*> flights_;
        string from_id_;
        string to_id_;
        Node* from_node_;
        Node* to_node_;
};
