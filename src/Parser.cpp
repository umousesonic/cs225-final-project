#include "Parser.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


Parser::Parser(string filename) {
    filename_ = filename;
    readFile(filename_);
}
Parser::Parser() {
    filename_ = "";
}

/* readFile(string filename)
 * Reads a .dat file and constructs csvector_
 * parameters: filename, the path to the dat file
 * returns: none
 * constructs csvector_
 */
void Parser::readFile(std::string filename) {
    // extension name checking, skip for now

    // Open file
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

    // Close file
    datfile.close();
}
/* printCsvector()
 * print out csvector_ for debugging.
 * parameters: none
 * returns: none
 * prints the entire csvector for debugging.
 */
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

vector<Edge*> Parser::parseEdges() {
    //Plan: get airline id, source airport id, destination id.
    //std::vector<Edge*> edges;
    
    map<string, Edge*> edgemap;
    for(size_t i = 0; i < csvector_.size(); i++) {
        Flight* insertion = new Flight(csvector_[i]->at(1), csvector_[i]->at(3), csvector_[i]->at(5));
        string pair1 = csvector_[i]->at(3) + " " + csvector_[i]->at(5);
        string pair2 = csvector_[i]->at(5) + " " + csvector_[i]->at(3);
        if (edgemap.count(pair1)) {
            edgemap.at(pair1)->addFlight(insertion);
        } else if (edgemap.count(pair2)) {
            edgemap.at(pair2)->addFlight(insertion);
        } else {
            edgemap.insert(std::pair<string, Edge*>(pair1, new Edge()));
            edgemap.at(pair1)->addFlight(insertion);
        }
    }
    vector<Edge*> edges;
    for(map<string, Edge*>::iterator it = edgemap.begin(); it != edgemap.end(); ++it) {
        edges.push_back(it->second);
    }
    return edges;
}