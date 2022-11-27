#include <catch2/catch_test_macros.hpp>

#include "Parser.h"
#include "Graph.h"


using namespace std;

TEST_CASE("Parser returns a non-empty vector")  {
    Parser myparser;
    myparser.readFile("../data/airports.dat.txt");
    vector<vector<string>*> v = myparser.getCsvector();

    REQUIRE(!v.empty());
}

TEST_CASE("Parser correctly parses comma seperated file") {
    Parser myparser;
    myparser.readFile("../tests/test_parser_small.dat.txt");
    vector<vector<string>*> v = myparser.getCsvector();

    REQUIRE(!v.empty());

    string first = v[0]->at(0);
    REQUIRE(first == "head");

    string second = v[0]->at(1);
    REQUIRE(second == "shoulder");
}