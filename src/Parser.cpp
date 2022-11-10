#include "Parser.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

Parser::Parser(string filename) {
    filename_ = filename;
}
Parser::Parser() {
    filename_ = "";
}

void Parser::readFile(std::string filename) {
    // extension name checking, skip for now
    //
    string line;
    ifstream datfile(filename);

    // Check if opening is successful
    if (!datfile.is_open()) cout << "Unable to open file" << endl;

    // Iterate through each line
    while (getline(datfile, line)) {
        stringstream ss(line);
        vector<string> *v = new vector<string>;
        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            v->push_back(substr);
        }
        csvector_.push_back(v);
    }
    datfile.close();
}

void Parser::printCsvector() {
    // Print code for debugging
    for (auto v : csvector_) {
        cout << "csvector_ item (";
        for (auto i : *v) {
            cout << "[" << i << "], ";
        }
        cout << ") " << endl;
    }
}