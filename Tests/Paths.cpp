#include "Paths.h"

Paths::Paths() : maxFlow(0) , occupied(0) {}

void Paths::addPath(vector<int> nodes, int flow) {
    auto it = paths.begin();
    while (it != paths.end()) {
        if (flow > (*it).flow) break;
        it++;
    }
    paths.insert(it,{std::move(nodes),flow,flow});
    maxFlow += flow;
}

int Paths::getMaxFlow() {
    return maxFlow;
}

void Paths::fitNPeople(int n) {
    if (n > maxFlow) {
        cout << "Not enough capacity for this number of people" << endl;
        return;
    }
    auto it = paths.begin();
    while (n != 0) {
        if (n <= (*it).flow) {
            (*it).freeFlow -= n;
            n = 0;
        } else {
            (*it).freeFlow = 0;
            n -= (*it).flow;
        }
        cout << "For flow of " << to_string((*it).flow - (*it).freeFlow);
        if (n == 1) cout << " person: \n";
        else cout << " people: \n";
        for (auto node : (*it).nodes) cout << node << " ";
        cout << endl;
        it++;
    }
}

void Paths::addNPeople(int n) {
    if (n > (maxFlow - occupied)) {
        cout << "Not enough capacity for this number of people" << endl;
        return;
    }
}
