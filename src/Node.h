#pragma once

#include "Edge.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node {
    public: 
        Node();
        Node(double latitude, double longitude, string id);
        double getLatitude();
        double getLongitude();
        void addEdgeFrom(Edge* edge);
        void addEdgeTo(Edge* edge);
        string getId();

    private:
        double latitude_;
        double longitude_;
        string id_;
        vector<Edge*> edges_from_;
        vector<Edge*> edges_to_;
};