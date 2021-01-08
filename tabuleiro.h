/*
Projeto: Jogo de Xadrez
3º Semestre de Ciências da Computação - UFSCar Sorocaba
Programação orientada a objetos
Profª Katti Faceli
Descrição:Definição da classe "tabuleiro", que tem como função imprimir o tabuleiro com as respectivas posições preenchidas por suas cores e peças
*/
#ifndef tabuleiro_h
#define tabuleiro_h
#include <iostream>
#include <string>
#include "posicao.h"

using namespace std;

class Tabuleiro {
   private:
    //matriz 8x8 que equivale ao tabuleiro
    Posicao* posicoes[8][8];

   public:
    //cria o tabuleiro
    Tabuleiro();
    //desenha o tabuleiro
    void desenhar();
    //Posicao** getPosicao();
    bool caminhoLivre(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
    Peca* getPeca(int linha, int coluna);
    void setPeca(Peca* peca, int i, int j);
    bool estaDentro(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
};

#endif