

#include "Viagem.h"

Viagem::Viagem(int origem,int destino,int capacidade):
    origem(origem),destino(destino),capacidade(capacidade){

}



void Viagem::setOrigem(int origem){
    this->origem=origem;
}


void Viagem::setTempo(int tempo) {
    this->tempo=tempo;
}

void Viagem::setCapacidade(int capacidade) {
    this->capacidade=capacidade;
}

void Viagem::setDestino(int destino){
    this->destino=destino;
}

void Viagem::setPreco(int preco){
    this->preco=preco;
}

int Viagem::getDestino(){
    return destino;
}
int Viagem::getOrigem(){
    return origem ;
}
int Viagem::getPreco() {
    return preco;
}
int Viagem::getCapacidade() {
    return capacidade;
}
int Viagem::getTempo() {
    return tempo;
}
