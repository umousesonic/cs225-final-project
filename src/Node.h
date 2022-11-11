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
        string getId();

    private:
        double latitude_;
        double longitude_;
        string id_;
        vector<Edge*> edges_;
};