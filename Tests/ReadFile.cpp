//
// Created by User on 20/05/2022.
//

#include "ReadFile.h"

Graph<int> ReadFile::readViagem(string filename) {
    Graph<int> graph;
    ifstream in;

    in.open("../Tests/Data/" + filename);

    if(!in.is_open()){
        cerr << "Unable to open file" << endl;
    }

    string s, numVertex, orig, dest, capacity, duration;


    getline(in, s); //txt header
    stringstream ss(s);
    getline(ss, numVertex, ' ');
    cout << numVertex << endl;
    for(int i = 1; i <= stoi(numVertex); i++){
        graph.addVertex(i);
    }

    while(getline(in, s)){
        stringstream ss(s);
        getline(ss, orig, ' ');
        getline(ss, dest, ' ');
        getline(ss, capacity, ' ');
        getline(ss, duration);

        cout << orig << " " << dest << " " << capacity << " " << duration << " " << endl;
    }
    return graph;
}