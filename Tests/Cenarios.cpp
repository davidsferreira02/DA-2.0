#include "Cenarios.h"

void Cenarios::cenario1_1(Graph* g) {
    g->pathMaximumCapacity(1,g->getSize());
}

void Cenarios::cenario1_2(Graph* g) {
    g->allPathsCapacityAndStops(1, g->getSize());
}

void Cenarios::cenario2_1(Graph* g) {
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
    g->FordFulkerson(1,g->getSize());
    Graph* solution = g->getFulkersonSolution();
    Paths* paths = solution->getPossiblePaths();
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


void Cenarios::cenario2_3(Graph* g) {
    g->FordFulkerson(1,g->getSize());
    Graph* solution = g->getFulkersonSolution();
    solution->printPaths(1,g->getSize());
}

void Cenarios::cenario2_4(Graph* g) {
    g->FordFulkerson(1,g->getSize());
    Graph* g2 = g->getFulkersonSolution();
    cout << "The group would reunite at " << g2->earliestStart() << endl;
}

void Cenarios::cenario2_5(Graph* g) {
    g->FordFulkerson(1,g->getSize());
    Graph* g2 = g->getFulkersonSolution();
    g2->earliestStart();
    g2->showWaitingTimes();
}
