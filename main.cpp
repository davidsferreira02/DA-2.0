#include <iostream>

#include "Tests/ReadFile.h"
#include "Tests/Cenarios.h"
#include "Tests/graph.h"

using namespace std;

int main() {
    /*
    cout << "\nFile " << to_string(12) << "\n";
    Graph g = ReadFile::readViagem(to_string(12));
    Cenarios::cenario2_1(&g);
    return 0;

    for(int i = 1; i < 12; i++) {
        cout << "\nFile " << to_string(i) << "\n";
        Graph g = ReadFile::readViagem(to_string(i));
        Cenarios::cenario2_4(&g);
    }

    return 0;
*/
    string fileName;
    cout << "Enter the number of the file:" << std::endl;
    cin >> fileName;
    Graph* g = ReadFile::readViagem(fileName);

    string scenario;
    cout << "Choose one  scenario" << endl;
    cin >> scenario;


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
