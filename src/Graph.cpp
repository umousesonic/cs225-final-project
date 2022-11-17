
#include "Graph.h"
#include "Parser.h"
#include "Flight.h"

Graph::Graph() {
    
}

void Graph::makeGraph(string nodefile, string edgefile) {
    Parser p_node(nodefile);
    Parser p_edge(edgefile);
    vector<Node*> nodes = p_node.parseNodes();
    vector<Edge*> edges = p_node.parseEdges();

    for (auto i : nodes) {
        nodemap_[i->getId()] = i;
    }

    for (auto i : edges) {
        // get node ids
        string from, to;
        from = i->getFromID();
        to = i->getToID();

        // Add nodes
        i->setFrom(nodemap_[from]);
        i->setTo(nodemap_[to]);

        // Connect nodes to edges
        nodemap_[from]->addEdgeFrom(i);
        nodemap_[to]->addEdgeTo(i);

    }



}

//void Graph::connect(Edge* input) {
//    for (unsigned i = 0; i < input->countFlights(); i++) {
//        Flight* test = input->getFlight(i);
//        Node* airport = nodemap_[test->getId()];
//        airport->addEdge(input);
//    }
//}