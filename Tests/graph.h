#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "minHeap.h"
#include "maxHeap.h"
#include "maxHeap_pair.h"
#include <vector>
#include <list>
#include <iostream>
#include "Paths.h"
#include <map>
#include <utility>

using namespace std;

class Paths;

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
        int capacity; //used in path of maximum capacity
        int predNode;
        int predEdge;
        bool visited;
        int earliestStart;
        int GrauE;
        int latestFinish;
        int GrauS;
    };
public:
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
     * @return Vector with the edges between the two nodes
     */
    vector<int> bfs(int v, int fv);
    /*!
     * Go to the previous nodes from the end to the start, using the node attribute predNode
     *
     * @param start Starting node
     * @param end End node
     * @return Empty vector if there is no path, or the path of nodes otherwise
     */
    vector<int> backtraceNode(int start, int end);
    /*!
     * Finds the minimum path using the dijkstra algorithm
     * Big 0 : O(|E| log|V|) (where V is the number of nodes and E the number of edges)
     *
     * @param sNode Starting node
     * @param endNode End node
     * @return Vector with the stops between the two nodes
     */
    vector<int> dijkstraPath(int sNode, int endNode);
    /*!
     * Get the maximum flow that can go trough a path
     *
     * @param path Path of edges
     * @param start Start node
     * @return Max Capacity of the path
     */
    int getMaxFlowForPath(vector<int> path, int start);
    /*!
     * Get the edge from the residual graph associated with the given edge
     *
     * @param srcNode
     * @param srcEdge
     * @return Number of the correspondent edge
     */
    int getOtherEdge(int srcNode, int srcEdge);
    /*!
     * Edmonds-Karp algorithm to find the max flow of the graph
     * Big O: O(E^2 * V) (where V is the number of nodes and E the number of edges)
     *
     * @param start
     * @param end
     */
    void FordFulkerson(int start, int end);
    /*!
     *
     * @return Graph with the Edmond-Karp solution
     */
    Graph* getFulkersonSolution();
    /*!
     *
     * @return Return a collection of all possible paths
     */
    Paths* getPossiblePaths();
    /*!
     * Print paths on the solution graph
     *
     * @param start Starting node
     * @param end End node
     */
    bool FordFulkerson(int start, int end);
    Graph* getFulkersonSolution();
    Paths* getPossiblePaths(int start, int end);
    void printPaths(int start, int end);

    /*!
     * Add edges in the opposite direction for the residual graph
     */
    void addOppositeEdges();
    /*!
     * Reset ES values
     * @return Nodes which their degrees of entry are 0
     */
    vector<int> resetEarliestStartValues();
    /*!
     *
     * @return Time of the ES for the finishing node
     */
    int earliestStart();
    /*!
     * Reset LF values
     * @return Nodes which their degress of entry are 1
     */
    bool hasEdge(int src, int dest);
    void addEdgesToShorterGraph(Graph* g, int node);
    Graph* getGraphForStart(int start);
    vector<int> resetLatestFinishValues();
    /*!
     *
     * @return Time of LF for the finishing node
     */
    int latestFinish();
    /*!
     * Print the waiting times in the various nodes
     */
    void showWaitingTimes();
    /*!
     * Get the path of maximum capacity in a graph
     * Big O: O((V + E) log2 |V|), (where V is the number of nodes and E the number of edges)
     *
     * @param start Starting node
     * @param end End node
     * @return Path of nodes
     */
    vector<int> pathMaximumCapacity(int start, int end);
    /*!
     * Retrieve the specificities of the optimal paths in terms of stops and capacity (pareto-optimal solutions)
     * @param start Starting node
     * @param end End node
     */
    void pathCapacityAndStops(int start, int end);
    /*!
     * Recursive/brute force solution to find the optimal paths in terms of stops and capacity (pareto-optimal solutions)
     * @param start Starting node
     * @param end End node
     */
    void allPathsCapacityAndStops(int start, int end);
    /*!
     * Helper function to the allPathsCapacityAndStops
     *
     * @param start Starting node
     * @param u Current node
     * @param d End node
     * @param path Current path
     * @param path_index Current index
     * @param minFlow Bfs flow
     * @param maxStops CCM stops
     * @param solution Map with the best flow for each path size
     */
    void allPathsCapacityAndStopsUtil(int start, int u, int d, vector<int> &path, int& path_index, int minFlow, int maxStops, map<int, int>& solution);
};

#endif
