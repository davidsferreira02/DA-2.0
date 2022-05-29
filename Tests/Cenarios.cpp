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
    g2->latestFinish();
    //cout << "Latest finish at " << g2->latestFinish();
}

void Cenarios::cenario2_5(Graph* g) {

}
