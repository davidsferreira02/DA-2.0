#include <iostream>

#include "Tests/ReadFile.h"
#include "Tests/Cenarios.h"
#include "Tests/graph.h"

using namespace std;

#define  NMAX 10000

int main() {
    cout << "\nFile " << to_string(4) << "\n";
    Graph* g = ReadFile::readViagem(to_string(4));
    g->allPathsCapacityAndStops(1, g->getSize());
    return 0;

    for(int i = 11; i < 12; i++) {
        cout << "\nFile " << to_string(i) << "\n";
        Graph* g = ReadFile::readViagem(to_string(i));
        Cenarios::cenario2_4(g);
    }

/*
    string fileName, scenario;
    char c;

    while (true) {
        cout << "Choose one of the following scenarios:" << endl;
        cout << "1.1 / 1.2 / 2.1 / 2.3 / 2.4 / 2.5" << endl;
        cout << "(Scenario 2.2 included in 2.1)" << endl;
        cin >> scenario;

        cout << "Enter the number of the file to be tested:" << endl;
        cin >> fileName;
        Graph* g = ReadFile::readViagem(fileName);

        if (scenario == "1.1") {
            Cenarios::cenario1_1(g);
        } else if (scenario == "1.2") {
            Cenarios::cenario1_2(g);
        }
        else if (scenario == "2.1") {
            Cenarios::cenario2_1( g);
        }
        else if (scenario == "2.3") {
            Cenarios::cenario2_3(g);
        }
        else if (scenario == "2.4") {
            Cenarios::cenario2_4(g);
        }
        else if (scenario == "2.5") {
            Cenarios::cenario2_5(g);
        }
        else {
            cout << "Invalid scenario" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        while (true) {
            cout << "\nNew cenario? (y/n)" << endl;
            cin >> c;
            if (c == 'n') {
                return 0;
            } if (c == 'y') break;
            cout << "Invalid input\n";
        }
    }
    /*


    /*
     switch (scenario) {
        case "1.1":
            Cenarios::cenario1_1(g);
            break;
        case "1.2":
            Cenarios::cenario1_2(g);
            break;
        case "2.1":
            Cenarios::cenario2_1(g);
            break;
        case "2.2":
            Cenarios::cenario2_2(g);
            break;
        case "2.3":
            Cenarios::cenario2_3(g);
            break;
        case "2.4":
            Cenarios::cenario2_4(g);
            break;
        case "2.5":
            Cenarios::cenario2_5(g);
            break;
        default:
            cout << "Invalid scenario" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            break;
    }
     */


    return 0;
}
