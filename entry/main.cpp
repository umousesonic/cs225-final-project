
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
    /*
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
            cout << edgepointers.at(i)->getFlight(j)->getSource() << "  ";
            cout << edgepointers.at(i)->getFlight(j)->getDestination() << endl;
            count++;
        }
        //cout << edgepointers.at(i)->getFlight(0)->getSource() << endl;
    }
    */
    Parser edgeParser;
    edgeParser.readFile("../data/routes.dat.txt");
    vector<Edge*> edgepointers = edgeParser.parseEdges();
    cout << edgepointers.size() << endl;
    size_t count = 0;
    /*
    //This loop simply tests if the parsed flight information worked.
    for(size_t i = 0; i < edgepointers.size(); i++) {
        for(size_t j = 0; j < edgepointers.at(i)->countFlights(); j++) {
            cout << edgepointers.at(i)->getFlight(j)->getId() << "  ";
            cout << edgepointers.at(i)->getFlight(j)->getFrom() << "  ";
            cout << edgepointers.at(i)->getFlight(j)->getTo() << endl;
        }
        //cout << edgepointers.at(i)->getFlight(0)->getSource() << endl;
    }
    cout << count << endl;
    */
   /*
   //This loop tests if parseEdges also fills the edge object's from id and to id
    for(size_t i = 0; i < edgepointers.size(); i++) {
        cout << edgepointers.at(i)->getFlight(0)->getId() << "  ";
        cout << edgepointers.at(i)->getFromID() << "  ";
        cout << edgepointers.at(i)->getToID() << endl;
        count++;
        //cout << edgepointers.at(i)->getFlight(0)->getSource() << endl;
    }
    */
    //This goes to each flight to verify that its source and destination IDs match the edge
    //source and destination ID.
    for(size_t i = 0; i < edgepointers.size(); i++) {
        for(size_t j = 0; j < edgepointers.at(i)->countFlights(); j++) {
            //cout << edgepointers.at(i)->getFlight(j)->getId() << "  ";
            //cout << edgepointers.at(i)->getFlight(j)->getFrom() << "  ";
            //cout << edgepointers.at(i)->getFlight(j)->getTo() << endl;
            string sourceID = edgepointers.at(i)->getFlight(j)->getFrom();
            string destID = edgepointers.at(i)->getFlight(j)->getTo();
            if(sourceID != edgepointers.at(i)->getFromID()) {
                cout << "Non-matching source ID for flight " + edgepointers.at(i)->getFlight(j)->getId() << endl;
            }
            if(destID != edgepointers.at(i)->getToID()) {
                cout << "Non-matching destination ID for flight " + edgepointers.at(i)->getFlight(j)->getId() << endl;
            }
        }
        //cout << edgepointers.at(i)->getFlight(0)->getSource() << endl;
    }
    cout << count << endl;
    cout << count << endl;
    return 0;
}