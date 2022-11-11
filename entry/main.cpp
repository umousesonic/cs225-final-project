
#include "Node.h"
#include "Flight.h"
#include "Edge.h"
#include "Parser.h"
#include <vector>
#include <iostream>

using namespace std;

int main() {
    Parser myparser;
    myparser.readFile("../data/airports.dat.txt");
    //myparser.printCsvector();
    Parser edgeParser;
    edgeParser.readFile("../data/routes.dat.txt");
    vector<Edge*> edgepointers = edgeParser.parseEdges();
    cout << edgepointers.size() << endl;
    return 0;
}