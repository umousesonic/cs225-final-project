#pragma once

#include "Node.h"
#include "Edge.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Parser {
    public:
        Parser(string filename);
        vector<Node*> parseNodes();
        vector<Edge*> parseEdges();
        // vector<Node*> parseRoutes(); // ??????????

    private:
        vector<vector<string>> csvector;
        string filename;
}