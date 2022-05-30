#ifndef DA_2_0_PATHS_H
#define DA_2_0_PATHS_H

#include <fstream>
#include <string>
#include <sstream>
#include <utility>
#include "graph.h"

using namespace std;

class Paths {
    struct Path {
        vector<int> nodes;
        int flow;
        int freeFlow;
    };

    vector<Path> paths;
    int maxFlow;
    int occupied;
public:
    Paths();
    void addPath(vector<int> nodes, int flow);
    int getMaxFlow();
    void fitNPeople(int n);
    void addNPeople(int n);
    bool fitNPeople(int n, bool add);
};

#endif //DA_2_0_PATHS_H
