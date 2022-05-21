#include <iostream>
#include "Tests/ReadFile.h"

using namespace std;

int main() {
    string fileName;
    cout << "Enter the number of the file:" << std::endl;
    cin >> fileName;

    ReadFile::readViagem(fileName);

    return 0;
}
