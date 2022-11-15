
#include "Graph.h"

Graph::Graph() {
    
}

void Graph::makeGraph() {

}

void Graph::connect(Edge* input) {
    for (unsigned i = 0; i < input->countFlights(); i++) {
        Flight* test = input->getFlight(i);
        Node* airport = nodeMap_[test->getId()];
        airport->addEdge(input);
    }
}