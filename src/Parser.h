#pragma once

#include "Node.h"
#include "Edge.h"
#include "Flight.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Parser {
    public:
        Parser();
        Parser(string filename);
        void readFile(string filename);
        vector<Node*> parseNodes();
        vector<Edge*> parseEdges();
        // vector<Node*> parseRoutes(); // ??????????

        void printCsvector();
        vector<vector<string>*> getCsvector();

    private:
        vector<vector<string>*> csvector_;
        string filename_;
};