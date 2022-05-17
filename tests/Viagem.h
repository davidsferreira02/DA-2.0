//

#ifndef UNTITLED7_VIAGEM_H
#define UNTITLED7_VIAGEM_H


class Viagem {
private:
    int origem;
    int destino;
    int capacidade;
    int tempo;
    int preco;


public:
    Viagem(const int origem, const int destino, const int capacidade);

    void setCapacidade(int capacidade);


    void setTempo(int tempo);

    void setPreco(int preco);

    void setDestino(int destino);


    void setOrigem(int origem);

    int getOrigem();

    int getPreco();

    int getDestino();

    int getCapacidade();


    int getTempo();
};

#endif //UNTITLED7_VIAGEM_H
