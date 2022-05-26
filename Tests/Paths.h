#ifndef DA_2_0_PATHS_H
#define DA_2_0_PATHS_H

#include <fstream>
#include <string>
#include <sstream>
#include "graph.h"

using namespace std;

class Paths {
    struct Path {
        vector<pair<int,int>> nodesWNextEdge;
        int flow;
        int ocupiedFlow;
        int duration;
    };

    vector<Path> paths;
    int maxFlow;
    int maxDuration;
public:
    Paths();
    void addPath()
};


Paths::Paths() : maxFlow(0), maxDuration(0) {}


#endif //DA_2_0_PATHS_H
