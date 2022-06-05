//
// Created by User on 20/05/2022.
//

#ifndef DA_2_0_READFILE_H
#define DA_2_0_READFILE_H

#include <fstream>
#include <string>
#include <sstream>
#include "graph.h"

using namespace std;

/*!
 * Read the contents of a test file and populate a graph
 */
class ReadFile {
public:
    static Graph* readViagem(string filename = "in01.txt");
};


#endif //DA_2_0_READFILE_H
