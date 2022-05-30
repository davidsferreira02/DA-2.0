#include "graph.h"
#include "Cenarip1_2.h"


#define NMAX 100

Cenario1_2::Cenario1_2(Graph g):
g(g){}


int * Cenario1_2::Capacity(int start,int end,int i) {
    //g.pathMaxCapacity
    capacity[i]=g.nodes[end].capacity;
    return capacity;
    }

int Cenario1_2:: GetMaxCapaticy(int capacity [],int i){
    int max=capacity[0];
    for(int c=0;c<i;c++){
        if(max<capacity[c]){
            max=capacity[c];
        }
    }
    return max;
}
