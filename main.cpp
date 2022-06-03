#include <iostream>

#include "Tests/ReadFile.h"
#include "Tests/Cenarios.h"
#include "Tests/graph.h"

using namespace std;

#define  NMAX 10000

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
    string fileName, node, scenario;
    int start, end;
    char c;

    cout << endl;

    while (true) {
        while (true) {
            cout << "Enter the number of the file to be tested (1-12):" << endl;
            cin >> fileName;
            try {
                if(stoi(fileName) < 1 || stoi(fileName) > 12){
                    cout << "Not valid file number" << endl;
                    continue;
                }
            } catch (exception &err) {
                cout << "Not a number" << endl;
                continue;
            }
            break;
        }

        Graph* g = ReadFile::readViagem(fileName);
        
        while (true) {
            cout << "What is the starting node (1-" << g->getSize() << ")?" << endl;
            cin >> node;
            try {
                start = stoi(node);
                if(start < 1 || start > g->getSize()){
                    cout << "Not valid node number" << endl;
                    continue;
                }
            } catch (exception &err) {
                cout << "Not a number" << endl;
                continue;
            }
            break;
        }

        while (true) {
            cout << "What is the finish node (1-" << g->getSize() << ")?" << endl;
            cin >> node;
            try {
                end = stoi(node);
                if(end <= 1 || end > g->getSize() || start == end){
                    cout << "Not valid node number" << endl;
                    continue;
                }
            } catch (exception &err) {
                cout << "Not a number" << endl;
                continue;
            }
            break;
        }
        

        cout << "Choose one of the following scenarios:" << endl;
        cout << "1.1 / 1.2 / 2.1 / 2.3 / 2.4 / 2.5" << endl;
        cout << "(Scenario 2.2 included in 2.1)" << endl;
        cin >> scenario;


        if (scenario == "1.1") {
            Cenarios::cenario1_1(g, start, end);
        } else if (scenario == "1.2") {
            Cenarios::cenario1_2(g, start, end);
        }
        else if (scenario == "2.1") {
            Cenarios::cenario2_1(g, start, end);
        }
        else if (scenario == "2.3") {
            Cenarios::cenario2_3(g, start, end);
        }
        else if (scenario == "2.4") {
            Cenarios::cenario2_4(g, start, end);
        }
        else if (scenario == "2.5") {
            Cenarios::cenario2_5(g, start, end);
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
     switch (scenario) {
        case "1.1":
            Cenarios::cenario1_1(g, start, end);
            break;
        case "1.2":
            Cenarios::cenario1_2(g, start, end);
            break;
        case "2.1":
            Cenarios::cenario2_1(g, start, end);
            break;
        case "2.2":
            Cenarios::cenario2_2(g, start, end);
            break;
        case "2.3":
            Cenarios::cenario2_3(g, start, end);
            break;
        case "2.4":
            Cenarios::cenario2_4(g, start, end);
            break;
        case "2.5":
            Cenarios::cenario2_5(g, start, end);
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
