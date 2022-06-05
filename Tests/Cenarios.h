#ifndef DA_2_0_CENARIOS_H
#define DA_2_0_CENARIOS_H

#include <fstream>
#include <string>
#include <sstream>
#include "graph.h"

using namespace std;

/*!
 * Class that handles each scenario
 */
class Cenarios {
public:
    static void cenario1_1(Graph* g, int start, int end);
    static void cenario1_2(Graph* g, int start, int end);
    static void cenario2_1(Graph* g, int start, int end);
    static void cenario2_3(Graph* g, int start, int end);
    static void cenario2_4(Graph* g, int start, int end);
    static void cenario2_5(Graph* g, int start, int end);
};

#endif //DA_2_0_CENARIOS_H
