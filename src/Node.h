#pragma once

#include "Edge.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Node {
    public: 
        Node();
        Node(long latitude, long longitude, string id); 
        long getLatitude();
        long getLongitude();
        string getId();

    private:
        long latitude_;
        long longitude_;
        string id_;
        vector<Edge*> edges_;
};