#include <iostream>
#include "Tests/ReadFile.h"
#include "Tests/Cenarios.h"

using namespace std;

int main() {
    cout << "\nFile " << to_string(12) << "\n";
    Graph g = ReadFile::readViagem(to_string(12));
    Cenarios::cenario2_1(&g);
    return 0;
    /*
    for(int i = 1; i < 12; i++) {
        cout << "\nFile " << to_string(i) << "\n";
        Graph g = ReadFile::readViagem(to_string(i));
        Cenarios::cenario2_4(&g);
    }

    return 0;

    string fileName;
    cout << "Enter the number of the file:" << std::endl;
    cin >> fileName;

    Graph g = ReadFile::readViagem(fileName);
    g.FordFulkerson(1,g.getSize());

    return 0;*/
}
