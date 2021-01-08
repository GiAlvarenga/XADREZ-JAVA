/*
Projeto: Jogo de Xadrez
3º Semestre de Ciências da Computação - UFSCar Sorocaba
Programação orientada a objetos
Profª Katti Faceli
Integrantes: Giovanni Alvarenga, Fábio Yamaya, João Victor Vilar
Implementação da classe "peca"
Descrição:Implementa as funções da classe "peca" contidas no arquivo .h
*/
#include "peca.h"

using namespace std;

//Construtor da classe ( ainda não utilizado )
Peca::Peca(int _cor, char _tipo) : cor(_cor), tipo(_tipo) {
    //Começa em falso pois nenhuma peça começa capturada
    capturado = false;
}

//Construtor para guardar as informações referentes a uma peça
/* Peca::Peca(int _cor, char _linha, int _coluna) : cor(_cor) {
    linha = _linha;
    coluna = _coluna;
    //Começa em falso pois nenhuma peça começa capturada
    capturado = false;
} */

//Destrutor da classe
Peca::~Peca() {
}
void Peca::desenha() {
}

bool Peca::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
}

int Peca::getCor() {
    return cor;
}

char Peca::getTipo() {
    return tipo;
}
bool Peca::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, bool haPeca) {
}