#include "Cenarios.h"

void Cenarios::cenario1_1(Graph* g, int start, int end) {
    vector<int> path = g->pathMaximumCapacity(start, end);
    if (path.size() == 0) { cout << "No path between the two nodes." << endl; }
    else {
        cout << "Capacity: " << g->nodes[g->n].capacity << endl;

        for (auto node: path) {
            cout << node << " ";
        }
    }
    cout << endl;
}

void Cenarios::cenario1_2(Graph* g, int start, int end) {
    cout << "Optimal solutions:" << endl;
    g->pathCapacityAndStops(start, end);
}

void Cenarios::cenario2_1(Graph* g, int start, int end) {
    string s;
    int n;
    while (true) {
        cout << "How many people will travel?" << endl;
        cin >> s;
        try {
            n = stoi(s);
        } catch (invalid_argument& excp) {
            cout << "Invalid input\n";
            continue;
        }
        break;
    }
    if (!g->FordFulkerson(start,end)) return;
    Graph* solution = g->getFulkersonSolution();
    Paths* paths = solution->getPossiblePaths(start,end);
    paths->fitNPeople(n, false);

    char c;
    while (true) {
        while (true) {
            cout << "Add more people? (y/n)" << endl;
            cin >> c;
            if (c == 'n') {
                return;
            } if (c == 'y') break;
            cout << "Invalid input\n";
        }
        while (true) {
            cout << "How many people to add?" << endl;
            cin >> s;
            try {
                n = stoi(s);
            } catch (invalid_argument& excp) {
                cout << "Invalid input\n";
                continue;
            }
            break;
        }
        if (paths->fitNPeople(n, true)) return;
    }
}


void Cenarios::cenario2_3(Graph* g, int start, int end) {
    if (!g->FordFulkerson(start,end)) return;
    Graph* solution = g->getFulkersonSolution();
    solution->printPaths(start,end);
}

void Cenarios::cenario2_4(Graph* g, int start, int end) {
    if (start != 1)
        g = g->getGraphForStart(start);
    if (!g->FordFulkerson(start,end)) return;
    Graph* g2 = g->getFulkersonSolution();
    cout << "The group would reunite at " << g2->earliestStart(end) << endl;
}

void Cenarios::cenario2_5(Graph* g, int start, int end) {
    if (start != 1)
        g = g->getGraphForStart(start);
    if (!g->FordFulkerson(start,end)) return;
    Graph* g2 = g->getFulkersonSolution();
    g2->earliestStart(end);
    g2->showWaitingTimes();
}
