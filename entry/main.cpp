
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
    vector<Node*> output = myparser.parseNodes();
    for (int i = 0; i < 5; i++) {
        cout << output[i]->getLatitude() << endl;
    }
    Parser edgeParser;
    edgeParser.readFile("../data/routes.dat.txt");
    vector<Edge*> edgepointers = edgeParser.parseEdges();
    cout << edgepointers.size() << endl;
    size_t count = 0;
    for(size_t i = 0; i < edgepointers.size(); i++) {
        for(size_t j = 0; j < edgepointers.at(i)->countFlights(); j++) {
            cout << edgepointers.at(i)->getFlight(j)->getId() << "  ";
            cout << edgepointers.at(i)->getFlight(j)->getFrom() << "  ";
            cout << edgepointers.at(i)->getFlight(j)->getTo() << endl;
        }
        //cout << edgepointers.at(i)->getFlight(0)->getSource() << endl;
    }
    cout << count << endl;
    return 0;
}