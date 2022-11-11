
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
    return 0;
}