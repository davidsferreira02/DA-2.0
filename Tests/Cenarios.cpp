#include "Cenarios.h"

void Cenarios::cenario1_1(Graph* g) {
    
}

void Cenarios::cenario1_2(Graph* g) {

}

void Cenarios::cenario2_1(Graph* g) {


}

void Cenarios::cenario2_2(Graph* g) {

}

void Cenarios::cenario2_3(Graph* g) {
    g->FordFulkerson(1,g->getSize());
    Graph* solution = g->getFulkersonSolution();
    solution->printPaths(1,g->getSize());
}

void Cenarios::cenario2_4(Graph* g) {
    g->FordFulkerson(1,g->getSize());
    Graph* g2 = g->getFulkersonSolution();
    cout << "The group would reunite at " << g2->earliestStart();
}

void Cenarios::cenario2_5(Graph* g) {
    g->FordFulkerson(1,g->getSize());
    Graph* g2 = g->getFulkersonSolution();
    g2->earliestStart();
    g2->showWaitingTimes();
}
