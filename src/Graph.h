#include "Parser.h"

#include <iostream>
#include <vector>
#include <string>

class Graph {
    public:
        Graph();
    
    private:
        void makeGraph();
        void connect(Edge* input);
        
        map<string, Node*> nodeMap_;
};
