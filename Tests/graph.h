#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "minHeap.h"
#include <vector>
#include <list>
#include <iostream>
#include "Paths.h"

using namespace std;

class Graph {
    struct Edge {
        int dest;   // Destination node
        int capacity; // An integer capacity
        int initialCapacity;
        int duration; //
    };

    struct Node {
        vector<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        int dist;
        int predNode;
        int predEdge;
        bool visited;
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirect; true: directed
    vector<Node> nodes; // The list of nodes being represented


private:
    /*!
     * Set all nodes values to default
     */
    void resetNodePathingValues();
    /*!
     * Starts in the end node and backtraces the lines and stops to the first stop
     *
     * @param start Starting node
     * @param end End node
     * @return Vector with the stops the bus goes trough
     */
    vector<int> backtrace(int start, int end);

public:
    /*!
     * Constructor: nr nodes and direction (default: undirected)
     *
     * @param nodes nr nodes
     * @param dir true if the graph is directed, false otherwise
     */
    Graph(int nodes, bool dir = false);
    int getSize();
    /*!
     * Add edge from source to destination with a certain capacity
     *
     * @param src Start node
     * @param dest End node
     * @param capacity Capacity of the connection
     * @param duration Duration of the connection
     */
    void addEdge(int src, int dest, int capacity, int duration);
    /*!
     * Prints all the nodes and the respective edges
     */
    void printGraph();
    /*!
     * Find the minimum distance between two nodes by using the Breadth-First Search
     * Big 0 : O(|V| + |E|) (where V is the number of nodes and E the number of edges)
     *
     * @param v Starting node
     * @param fv End node
     * @return Vector with the stops between the two nodes
     */
    vector<int> bfs(int v, int fv);
    /*!
     * Finds the minimum path using the dijkstra algorithm
     * Big 0 : O(|E| log|V|) (where V is the number of nodes and E the number of edges)
     *
     * @param sNode Starting node
     * @param endNode End node
     * @return Vector with the stops between the two nodes
     */
    vector<int> dijkstraPath(int sNode, int endNode);
    int getMaxFlowForPath(vector<int> path, int start);
    int getOtherEdge(int srcNode, int srcEdge);
    void FordFulkerson(int start, int end);
    Graph* getFulkersonSolution();
    //Paths* getPossiblePaths(int start, int end);
    void printPaths(int start, int end);
};

#endif
