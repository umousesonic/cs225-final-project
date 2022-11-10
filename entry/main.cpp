
#include "Node.h"
#include "Flight.h"
#include "Edge.h"
#include "Parser.h"

int main() {
    Parser myparser;
    myparser.readFile("../data/airports.dat.txt");
    myparser.printCsvector();
    return 0;
}