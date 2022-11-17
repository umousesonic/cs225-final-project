#include "Parser.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
class Graph {
    public:
        Graph();
    
    private:
        void makeGraph();
        void connect(Edge* input);

        map<string, Node*> nodemap_;
};
