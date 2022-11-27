#include <catch2/catch_test_macros.hpp>
#include <string>
#include "Parser.h"
#include "Graph.h"


using namespace std;

TEST_CASE("Graph creates a graph") {
    Graph mygraph("../data/airports.dat.txt", "../data/routes.dat.txt");

    REQUIRE(!mygraph.getEdges().empty());
    REQUIRE(!mygraph.getNodes().empty());
}