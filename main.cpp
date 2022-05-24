#include <iostream>
#include "ReadFile.h"

using namespace std;

#define  NMAX 10000

int main() {

    int localPartida[NMAX];
    int localChegada[NMAX];
    int capacidade[NMAX];
    int nos = 0;
    int duracao[NMAX];
    int autocarros = 0;
    FILE *file1 = fopen("tests/Data/Tests/Tests/int01.txt", "r");
    fscanf(file1, "%d ", &nos);
    fscanf(file1, "%d\n", &autocarros);
    for (int i = 0; i < autocarros; i++) {
        fscanf(file1, "%d ", &localPartida[i]);
        fscanf(file1, "%d ", &localChegada[i]);
        fscanf(file1, "%d ", &capacidade[i]);
        fscanf(file1, "%d ", &duracao[i]);
    }
    FILE *file2 = fopen("tests/Data/Tests/Tests/int02.txt", "r");
    fscanf(file2, "%d ", &nos);
    fscanf(file2, "%d\n", &autocarros);
    for (int i = 0; i < autocarros; i++) {
        fscanf(file2, "%d ", &localPartida[i]);
        fscanf(file2, "%d ", &localChegada[i]);
        fscanf(file2, "%d ", &capacidade[i]);
        fscanf(file2, "%d ", &duracao[i]);
    }
    FILE *file3 = fopen("tests/Data/Tests/Tests/int03.txt", "r");
    fscanf(file3, "%d ", &nos);
    fscanf(file3, "%d\n", &autocarros);
    for (int i = 0; i < autocarros; i++) {
        fscanf(file3, "%d ", &localPartida[i]);
        fscanf(file3, "%d ", &localChegada[i]);
        fscanf(file3, "%d ", &capacidade[i]);
        fscanf(file3, "%d ", &duracao[i]);
    }
    FILE *file4 = fopen("tests/Data/Tests/Tests/int04.txt", "r");
    fscanf(file4, "%d ", &nos);
    fscanf(file4, "%d\n", &autocarros);
    for (int i = 0; i < autocarros; i++) {
        fscanf(file4, "%d ", &localPartida[i]);
        fscanf(file4, "%d ", &localChegada[i]);
        fscanf(file4, "%d ", &capacidade[i]);
        fscanf(file4, "%d ", &duracao[i]);
    }
    FILE *file5 = fopen("tests/Data/Tests/Tests/int05.txt", "r");
    fscanf(file5, "%d ", &nos);
    fscanf(file5, "%d\n", &autocarros);
    for (int i = 0; i < autocarros; i++) {
        fscanf(file5, "%d ", &localPartida[i]);
        fscanf(file5, "%d ", &localChegada[i]);
        fscanf(file5, "%d ", &capacidade[i]);
        fscanf(file5, "%d ", &duracao[i]);
    }
    FILE *file6 = fopen("tests/Data/Tests/Tests/int06.txt", "r");
    fscanf(file6, "%d ", &nos);
    fscanf(file6, "%d\n", &autocarros);
    for (int i = 0; i < autocarros; i++) {
        fscanf(file6, "%d ", &localPartida[i]);
        fscanf(file6, "%d ", &localChegada[i]);
        fscanf(file6, "%d ", &capacidade[i]);
        fscanf(file6, "%d ", &duracao[i]);
    }
    FILE *file7 = fopen("tests/Data/Tests/Tests/int07.txt", "r");
    fscanf(file7, "%d ", &nos);
    fscanf(file7, "%d\n", &autocarros);
    for (int i = 0; i < autocarros; i++) {
        fscanf(file7, "%d ", &localPartida[i]);
        fscanf(file7, "%d ", &localChegada[i]);
        fscanf(file7, "%d ", &capacidade[i]);
        fscanf(file7, "%d ", &duracao[i]);
    }
    FILE *file8 = fopen("tests/Data/Tests/Tests/int08.txt", "r");
    fscanf(file8, "%d ", &nos);
    fscanf(file8, "%d\n", &autocarros);
    for (int i = 0; i < autocarros; i++) {
        fscanf(file8, "%d ", &localPartida[i]);
        fscanf(file8, "%d ", &localChegada[i]);
        fscanf(file8, "%d ", &capacidade[i]);
        fscanf(file8, "%d ", &duracao[i]);
    }
    FILE *file9 = fopen("tests/Data/Tests/Tests/int09.txt", "r");
    fscanf(file9, "%d ", &nos);
    fscanf(file9, "%d\n", &autocarros);
    for (int i = 0; i < autocarros; i++) {
        fscanf(file9, "%d ", &localPartida[i]);
        fscanf(file9, "%d ", &localChegada[i]);
        fscanf(file9, "%d ", &capacidade[i]);
        fscanf(file9, "%d ", &duracao[i]);
    }
    FILE *file10 = fopen("tests/Data/Tests/Tests/int10.txt", "r");
    fscanf(file10, "%d ", &nos);
    fscanf(file10, "%d\n", &autocarros);
    for (int i = 0; i < autocarros; i++) {
        fscanf(file10, "%d ", &localPartida[i]);
        fscanf(file10, "%d ", &localChegada[i]);
        fscanf(file10, "%d ", &capacidade[i]);
        fscanf(file10, "%d ", &duracao[i]);
    }

    string fileName;
    cout << "Enter the number of the file:" << std::endl;
    cin >> fileName;

    ReadFile::readViagem(fileName);


    return 0;
}
