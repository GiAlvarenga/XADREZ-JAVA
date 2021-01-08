/*
Projeto: Jogo de Xadrez
3º Semestre de Ciências da Computação - UFSCar Sorocaba
Programação orientada a objetos
Profª Katti Faceli
Integrantes: Giovanni Alvarenga, Fábio Yamaya, João Victor Vilar
Implementação da classe "cavalo"
Descrição:Definição das classes "cavalo" 
*/
#ifndef cavalo_h
#define cavalo_h
#include <iostream>
#include "peca.h"

using namespace std;

class Cavalo : public Peca {
   public:
    //Construtor e destrutor
    Cavalo(int _cor, char _tipo);
    //~Cavalo();

    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
    void desenha();
};

#endif