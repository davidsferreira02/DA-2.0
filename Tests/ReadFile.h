//
// Created by User on 20/05/2022.
//

#ifndef DA_2_0_READFILE_H
#define DA_2_0_READFILE_H

#include <fstream>
#include <string>
#include <sstream>
#include "Graph.h"

using namespace std;

class ReadFile {
public:
    static Graph<int> readViagem(string filename = "in01.txt");
};


#endif //DA_2_0_READFILE_H
