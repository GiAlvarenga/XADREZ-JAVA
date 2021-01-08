/*
Projeto: Jogo de Xadrez
3º Semestre de Ciências da Computação - UFSCar Sorocaba
Programação orientada a objetos
Profª Katti Faceli
Descrição:Definição da classe "bispo"
*/
#ifndef bispo_h
#define bispo_h
#include <iostream>
#include "peca.h"

using namespace std;

class Bispo : public Peca {
   public:
    Bispo(int _cor, char _tipo);
    //~Bispo();
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
    void desenha();
};

#endif