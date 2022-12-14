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
        void makeGraph(string nodefile, string edgefile);
        void connect(Edge* input);

        map<string, Node*> nodemap_;
        vector<Node*> nodes_;
        vector<Edge*> edges_;
};
