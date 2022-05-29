#include <iostream>
#include <Cenarios.h>
#include "ReadFile.h"
#include "graph.h"

using namespace std;

int main() {
    string fileName;
    cout << "Enter the number of the file:" << std::endl;
    cin >> fileName;
    ReadFile::readViagem(fileName);

    string scenario;
    cout << "Choose one  scenario" << endl;
    cin >> scenario;

    graph * g;
    if (scenario == "1_1") {
        Cenarios::cenario1_1(g);
    } else if (scenario == "1_2") {
        Cenarios::cenario1_2(g);
    }
    else if (scenario == "2_1") {
        Cenarios::cenario2_1( g);
    }
    else if (scenario == "2_2") {
        Cenarios::cenario2_2(g);
    }
    else if (scenario == "2_3") {
        Cenarios::cenario2_3(g);
    }
    else if (scenario == "2_4") {
        Cenarios::cenario2_4(g);
    }
    else if (scenario == "2_5") {
        Cenarios::cenario2_5(g);
    }
    else {
        cout << "Invalid scenario" << endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }


    return 0;
}