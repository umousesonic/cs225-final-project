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
        //Does not add edge if either the source or destination airport IDs are invalid.
        //Note that this currently does not exclude invalid airline IDs.
        if(csvector_[i]->at(1) == "\\N" || csvector_[i]->at(3) == "\\N" || csvector_[i]->at(5) == "\\N") {
            continue;
        }
        Flight* insertion = new Flight(csvector_[i]->at(0) + " " + csvector_[i]->at(1), csvector_[i]->at(3), csvector_[i]->at(5));
        string pair1 = csvector_[i]->at(3) + " " + csvector_[i]->at(5);
        if (edgemap.count(pair1)) {
            edgemap.at(pair1)->addFlight(insertion);
        } else {
            edgemap.insert(std::pair<string, Edge*>(pair1, new Edge()));
            edgemap.at(pair1)->addFlight(insertion);
            edgemap.at(pair1)->setFromID(csvector_[i]->at(3));
            edgemap.at(pair1)->setToID(csvector_[i]->at(5));
        }
    }
    vector<Edge*> edges;
    for(map<string, Edge*>::iterator it = edgemap.begin(); it != edgemap.end(); ++it) {
        edges.push_back(it->second);
    }
    return edges;
}


// Function assumes that Airport.dat is the file that is being read
vector<Node*> Parser::parseNodes() {
    vector<Node*> toReturn;
    for (unsigned i = 0; i < csvector_.size(); i++) {
        string id = csvector_[i]->at(0);
        string lati;
        string longi;
        // Checking if there is edge case of extra comma within line
        if (csvector_[i]->size() > 14) {
            lati = csvector_[i]->at(7);
            longi = csvector_[i]->at(8);
        } else {
            lati = csvector_[i]->at(6);
            longi = csvector_[i]->at(7);
        }
        double latitude = stod(lati);
        double longitude = stod(longi);
        Node* insert = new Node(latitude, longitude, id);
        toReturn.push_back(insert);
    }
    return toReturn;
}