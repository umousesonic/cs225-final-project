#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Flight {
    public:
        Flight(string id, string from, string to);
        string getId();
        string getFrom();
        string getTo();

    private:
        string id_; 
        string from_;
        string to_;

};