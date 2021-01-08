/*
Projeto: Jogo de Xadrez
3º Semestre de Ciências da Computação - UFSCar Sorocaba
Programação orientada a objetos
Profª Katti Faceli
Descrição:Definição da classe "peao"
*/
#ifndef peao_h
#define peao_h
#include <iostream>
#include "peca.h"

using namespace std;

class Peao : public Peca {
   private:
    //Flag para saber se é possível que o peão se mova 2 casas devido ao movimento primário
    bool jaMoveu = false;

   public:
    //Desenha a peça na tela
    void desenha();
    //Destrutores e construtores
    Peao(int _cor, char _tipo);
    //~Peao();
    bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, bool haPeca);
};

#endif