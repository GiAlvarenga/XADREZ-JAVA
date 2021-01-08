/*
Projeto: Jogo de Xadrez
3º Semestre de Ciências da Computação - UFSCar Sorocaba
Programação orientada a objetos
Profª Katti Faceli
Descrição:Definição da classe "jogo", chamada ao iniciar o programa para criar os principais objetos necessários e receber os nomes dos jogadores
*/
#ifndef jogo_h
#define jogo_h
#include <iostream>
#include <string>
#include "jogador.h"
#include "peca.h"
#include "tabuleiro.h"

class Jogo {
   private:
    Tabuleiro* tabuleiro1;
    Jogador* jogador1;
    Jogador* jogador2;
    Peca* pecasBrancas[16];
    Peca* pecasPretas[16];
    //Estado se refere à situação "em xeque" ou "xeque-mate"
    string estado;
    int turnoJogador;

   public:
    Jogo();
    //Usado ao iniciar o jogo para criar os objetos jogador e tabuleiro
    //void inicializar();
    //Métodos para obter objetos devido ao escopo
    Tabuleiro* getTabuleiro();
    Jogador* getJogador1();
    Jogador* getJogador2();
    ~Jogo();
    void turnos();
    bool movimenta(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
    bool movimentoValido(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
    bool estaEmXeque(int cor);
    void achaRei(int cor, int posicaoRei[]);
    bool verificaXeque(int iRei, int jRei, int cor);
    bool estaEmXequeMate(int cor);
};

#endif