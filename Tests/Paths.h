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
    /*!
     * Add a path to the vector of paths
     */
    void addPath(vector<int> nodes, int flow);
    /*!
     * Get a path's max flow
     * @return Integer representing the path maximum capacity
     */
    int getMaxFlow();
    void fitNPeople(int n);
    void addNPeople(int n);
    /*!
     * Add n people to the path
     *
     * @param n Number of people
     * @param add Boolean - True if it is to add, false if it is the first time using the function
     * @return True if it was possible, false otherwise
     */
    bool fitNPeople(int n, bool add);
};

#endif //DA_2_0_PATHS_H
