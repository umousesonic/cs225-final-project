#include "Graph.h"
#include "Parser.h"
#include "Flight.h"

Graph::Graph() {
    
}

void Graph::makeGraph(string nodefile, string edgefile) {
    Parser p_node(nodefile);
    Parser p_edge(edgefile);
    nodes_ = p_node.parseNodes();
    edges_ = p_node.parseEdges();

    for (auto i : nodes_) {
        nodemap_[i->getId()] = i;
    }

    for (auto i : edges_) {
        // get node ids
        string from, to;
        from = i->getFromID();
        to = i->getToID();

        // Add nodes
        i->setFromNode(nodemap_[from]);
        i->setToNode(nodemap_[to]);

        // Connect nodes to edges
        nodemap_[from]->addEdgeFrom(i);
        nodemap_[to]->addEdgeTo(i);
    }
}
