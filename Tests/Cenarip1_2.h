
#include "minHeap.h"
#include "maxHeap.h"
#include <vector>
#include <list>
#include <iostream>
#include "graph.h"

using namespace std;
class Cenario1_2{
public:
 Cenario1_2(Graph g);
 int *Capacity(int start,int end,int i);
 int GetMaxCapaticy(int capacity [],int i);

private:
 Graph g;
 int capacity[];
};