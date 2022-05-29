#include "graph.h"
#include <queue>
#include <algorithm>

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

int Graph::getSize() { return n; }

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, int capacity, int duration) {
    if (src<1 || src>nodes.size() || dest<1 || dest>nodes.size()) return;
    nodes[src].adj.push_back({dest, capacity, capacity,duration});
    if (!hasDir) nodes[dest].adj.push_back({src, capacity, capacity, duration});
}

void Graph::printGraph(){
    for(int v = 1; v < nodes.size(); v++){

        cout << v << " : ";
        for(auto e : nodes[v].adj){
            cout << e.dest << " ";
        }
        cout << endl;
    }
}

void Graph::resetNodePathingValues() {
    for (int i=1; i<=n; i++) {
        nodes.at(i).dist=INT32_MAX;
        nodes.at(i).visited=false;
        nodes.at(i).predNode=-1;
        nodes.at(i).predEdge=-1;
    }
}

/*
vector<int> Graph::backtrace(int start, int end) {
    if(nodes[end].predEdge == -1){return {};}
    vector<int> path = {end};
    int prevNode,edgeIndex,edgeNum = 0, curNode = end;
    while (curNode != start){
        prevNode = nodes[curNode].adj[nodes[curNode].predEdge].dest;
        for(int i = 0; i < nodes[curNode].adj.size(); i++)
            if (nodes[curNode].adj[i].dest == prevNode) {
                edgeNum++;
                if (i == nodes[curNode].predEdge) break;
            }
        for(int i = 0; i < nodes[prevNode].adj.size(); i++)
            if (nodes[prevNode].adj[i].dest == curNode) {
                edgeNum--;
                if (edgeNum == 0) edgeIndex = i;
            }
        path.insert(path.begin(),edgeIndex);
        curNode = prevNode;
    }
    return path;
}
*/

vector<int> Graph::backtrace(int start, int end) {
    if(nodes[end].predNode== -1){return {};}
    vector<int> path = {};
    int curNode = end;
    while (curNode != start){
        path.insert(path.begin(),nodes[curNode].predEdge);
        curNode = nodes[curNode].predNode;
    }
    return path;
}

vector<int> Graph::bfs(int v, int fv) {
    if(v == fv){return {v};}

    resetNodePathingValues();

    queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v].visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        for (int i = 0; i < nodes[u].adj.size();i++) {
            Edge e = nodes[u].adj[i];
            if (e.capacity == 0) continue;
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                nodes[w].predNode = u;
                nodes[w].predEdge = i;
                nodes[w].dist = nodes[u].dist + 1;
                if(w == fv){return backtrace(v, fv);}
            }
        }
    }
    return {};
}

int Graph::getMaxFlowForPath(vector<int> path, int start) {
    int curNode = start, flow = INT32_MAX;
    Edge curEdge;
    for( auto e: path) {
        curEdge = nodes[curNode].adj[e];
        if (curEdge.capacity < flow) flow = curEdge.capacity;
        curNode = curEdge.dest;
    }
    return flow;
}

int Graph::getOtherEdge(int srcNode, int srcEdge) {
    int destNode = nodes[srcNode].adj[srcEdge].dest;
    int edgeNum = 0;
    for(int i = 0; i < nodes[srcNode].adj.size(); i++)
        if (nodes[srcNode].adj[i].dest == destNode) {
            edgeNum++;
            if (i == srcEdge) break;
        }
    for(int i = 0; i < nodes[destNode].adj.size(); i++)
        if (nodes[destNode].adj[i].dest == srcNode) {
            edgeNum--;
            if (edgeNum == 0) return i;
        }
    return -1;
}

Graph* Graph::getFulkersonSolution() {
    Graph* g = new Graph(n, hasDir);

    for (int i = 1; i <= n; i++) {
        for (auto e: nodes[i].adj) {
            if (e.initialCapacity == 0 && e.capacity != 0) {
                g->addEdge(e.dest, i, e.capacity, e.duration);
            }
        }
    }
    return g;
}

Paths* Graph::getPossiblePaths() {
    Paths* paths = new Paths();
    vector<int> path, nodesPath;
    int flow;
    while (!(path = bfs(1, n)).empty()) {
        nodesPath = {};
        flow = getMaxFlowForPath(path, 1);
        int curNode = 1;
        for( auto e: path) {
            nodesPath.push_back(curNode);
            nodes[curNode].adj[e].capacity -= flow;
            curNode = nodes[curNode].adj[e].dest;
        }
        nodesPath.push_back(n);
        paths->addPath(nodesPath,flow);
    }
    return paths;
}

void Graph::printPaths(int start, int end) {
    vector<int> path;
    int flow, sumflow = 0;
    while (!(path = bfs(start, end)).empty()) {
        flow = getMaxFlowForPath(path, start);
        sumflow += flow;
        cout << "For flow of " << to_string(flow);
        if (flow == 1) cout << " person: \n";
        else cout << " people: \n";
        int curNode = start;
        for( auto e: path) {
            cout << to_string(curNode) << " ";
            nodes[curNode].adj[e].capacity -= flow;
            curNode = nodes[curNode].adj[e].dest;
        }
        cout << to_string(end) << "\n";
    }
    cout << "Maximum capacity of the group: " << to_string(sumflow) << endl;
}

void Graph::FordFulkerson(int start, int end) {
    vector<int> path;
    int flow;
    while (!(path = bfs(start, end)).empty()) {
        flow = getMaxFlowForPath(path, start);
        int curNode = start;
        Edge curEdge;
        for( auto e: path) {
            curEdge = nodes[curNode].adj[e];
            nodes[curNode].adj[e].capacity -= flow; // curEdge.capacity -= flow
            nodes[curEdge.dest].adj[getOtherEdge(curNode,e)].capacity += flow;  //simetricEdge.capacity += flow
            curNode = nodes[curNode].adj[e].dest;
        }
    }
}

vector<int> Graph::dijkstraPath(int sNode, int endNode) {
    resetNodePathingValues();

    MinHeap<int, int> minHeap = MinHeap<int, int>(this->n, -1);

    for(int i = 1; i <= n; i++){
        minHeap.insert(i, nodes[i].dist);
    }

    minHeap.decreaseKey(sNode, nodes[sNode].dist = 0);

    while(minHeap.getSize() > 0) {
        int cNode = minHeap.removeMin();
        nodes.at(cNode).visited=true;

        for (Edge edge: nodes.at(cNode).adj) {
            if (!nodes[edge.dest].visited && nodes.at(cNode).dist + edge.capacity < nodes.at(edge.dest).dist) {
                minHeap.decreaseKey(edge.dest, nodes[edge.dest].dist = nodes[cNode].dist + edge.capacity);
                //nodes[edge.dest].pred = cNode;    NOT ADAPTED YET
            }
        }
    }

    return backtrace(sNode, endNode);
}

void Graph::addOppositeEdges() {
    for (int i = 1; i <= n; i++) {
        for (auto e : nodes[i].adj) {
            if (e.capacity != -1)
                addEdge(e.dest,i,-1,e.duration);
        }
    }
}

vector<int> Graph::resetEarliestStartValues() {
    for (int i=1; i<=n; i++) {
        nodes.at(i).earliestStart = 0;
        nodes.at(i).GrauE = 0;
        nodes.at(i).predNode = -1;
        nodes.at(i).predEdge = -1;

    }
    for (int i=1; i<=n; i++)
        for (auto e: nodes.at(i).adj)
            nodes.at(e.dest).GrauE += 1;

    vector<int> S = {};
    for (int i=1; i<=n; i++)
        if (nodes.at(i).GrauE == 0) S.push_back(i);

    return S;
}

int Graph::earliestStart() {
    vector<int> S = resetEarliestStartValues();
    int durMin = -1, vf = -1;
    while (!S.empty()) {
        int v = S.back();
        S.pop_back();
        if (durMin < nodes[v].earliestStart) {
            durMin = nodes[v].earliestStart;
            vf = v;
        }
        for (auto e : nodes[v].adj) {
            if (nodes[e.dest].earliestStart < nodes[v].earliestStart + e.duration) {
                nodes[e.dest].earliestStart = nodes[v].earliestStart + e.duration;
                nodes[e.dest].predNode = v;     //falta ir buscar a predEdge
            }
            nodes[e.dest].GrauE -= 1;
            if (nodes[e.dest].GrauE == 0) S.push_back(e.dest);
        }
    }
    return nodes[n].earliestStart;
}

vector<int> Graph::resetLatestFinishValues() {
    earliestStart();

    for (int i=1; i<=n; i++) {
        nodes.at(i).latestFinish=nodes.at(n).earliestStart;
        nodes.at(i).GrauS = 0;
    }
    for (int i=1; i<=n; i++)
        for (auto e: nodes.at(i).adj)
            nodes.at(i).GrauS += 1;

    vector<int> S = {};
    for (int i=1; i<=n; i++)
        if (nodes.at(i).GrauS == 0) S.push_back(i);

    addOppositeEdges();
    return S;
}

int Graph::latestFinish() {
    vector<int> S = resetLatestFinishValues();

    while (!S.empty()) {
        int v = S.back(); S.pop_back();
        int i = -1;
        for (auto e : nodes[v].adj){
            i++;
            if (e.initialCapacity != -1) continue;
            if (nodes[e.dest].latestFinish > nodes[v].latestFinish - e.duration)
                nodes[e.dest].latestFinish = nodes[v].latestFinish - e.duration;
            nodes[e.dest].GrauS -= 1;
            if (nodes[e.dest].GrauS == 0) S.push_back(e.dest);
        }
    }

    for (int i = 1; i <= n; i++) {
        cout  << i << ": " << nodes[i].earliestStart << " / " << nodes[i].latestFinish << endl;
    }
    return nodes[n].latestFinish;
}

void Graph::showWaitingTimes() {
    int wTime, maxWaitTime = 0;
    cout << "After going from node [n] to node [w] there is a waiting time of [t] at [w] to continue." << endl;
    cout << "[n] -> [w] : [t]" << endl;
    for (int i = 1; i < n; i++) {
        for (auto e : nodes[i].adj) {
            wTime = nodes[e.dest].earliestStart - nodes[i].earliestStart - e.duration;
            if (wTime == 0) continue;
            if (wTime > maxWaitTime) maxWaitTime = wTime;
            cout << i << "->" << e.dest << ":" << wTime << endl;
        }
    }
    cout << "\nThe maximum waiting time is " << maxWaitTime << " at nodes: ";
    for (int i = 1; i < n; i++) {
        for (auto e : nodes[i].adj) {
            wTime = nodes[e.dest].earliestStart - nodes[i].earliestStart - e.duration;
            if (wTime == maxWaitTime) cout << e.dest << " ";
        }
    }
    cout << endl;
}