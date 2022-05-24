#include <iostream>
#include "Tests/ReadFile.h"

using namespace std;

int main() {

    for(int i = 1; i < 12; i++) {
        cout << "\nFile " << to_string(i) << "\n";
        Graph g = ReadFile::readViagem(to_string(i));
        g.pathMaximumCapacity(1,g.getSize());
    }

    return 0;

    string fileName;
    cout << "Enter the number of the file:" << std::endl;
    cin >> fileName;

    Graph g = ReadFile::readViagem(fileName);
    g.FordFulkerson(1,g.getSize());

    return 0;
}
