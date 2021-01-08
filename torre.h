/*
Projeto: Jogo de Xadrez
3º Semestre de Ciências da Computação - UFSCar Sorocaba
Programação orientada a objetos
Profª Katti Faceli
Descrição:Definição da classe "torre"
*/
#ifndef torre_h
#define torre_h
#include <iostream>
#include "peca.h"

using namespace std;

class Torre : public Peca {
   public:
    //Construtor e destrutor
    Torre(int _cor, char _tipo);
    //~Torre();
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
    void desenha();
};

#endif