/*
Projeto: Jogo de Xadrez
3º Semestre de Ciências da Computação - UFSCar Sorocaba
Programação orientada a objetos
Profª Katti Faceli
Descrição:Definição da classe "rei"
*/
#ifndef rei_h
#define rei_h
#include <iostream>
#include "peca.h"

using namespace std;

class Rei : public Peca {
   public:
    //Construtor e destrutor
    Rei(int _cor, char _tipo);
    //~Rei();
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
    void desenha();
};

#endif