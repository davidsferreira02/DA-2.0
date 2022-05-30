//
// Created by User on 20/05/2022.
//

#include "ReadFile.h"

Graph* ReadFile::readViagem(string filename) {

    ifstream in;
    if (stoi(filename) < 10) filename = '0' + filename;

    in.open("../Tests/Data/in" + filename + ".txt");

    if(!in.is_open()){
        cerr << "Unable to open file" << endl;
    }

    string s, numNodes, orig, dest, capacity, duration;


    getline(in, s); //txt header
    stringstream ss(s);
    getline(ss, numNodes, ' ');
    //cout << numNodes << endl;

    Graph* graph = new Graph(stoi(numNodes), true);

    while(getline(in, s)){
        stringstream ss(s);
        getline(ss, orig, ' ');
        getline(ss, dest, ' ');
        getline(ss, capacity, ' ');
        getline(ss, duration);

        //cout << orig << " " << dest << " " << capacity << " " << duration << " " << endl;

        graph->addEdge(stoi(orig), stoi(dest), stoi(capacity), stoi(duration));
        graph->addEdge(stoi(dest), stoi(orig), 0, stoi(duration));
    }

    return graph;
}