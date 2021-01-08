/*
Projeto: Jogo de Xadrez
3º Semestre de Ciências da Computação - UFSCar Sorocaba
Programação orientada a objetos
Profª Katti Faceli
Integrantes: Giovanni Alvarenga, Fábio Yamaya, João Victor Vilar
Implementação da classe "cavalo"
Descrição:Implementa as funções da classe "cavalo" contidas no arquivo .h
*/
#include "cavalo.h"
#include <stdlib.h>

//Construtor da classe ( ainda não utilizado )
Cavalo::Cavalo(int _cor, char _tipo) : Peca(_cor, _tipo) {}

//Destrutor da classe
//Cavalo::~Cavalo(){}

bool Cavalo::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    //Calcula a diferença entre linha e coluna para obter o movimento
    int diferencaLinha = linhaDestino - linhaOrigem;
    int diferencaColuna = colunaDestino - colunaOrigem;

    diferencaLinha = abs(diferencaLinha);
    diferencaColuna = abs(diferencaColuna);

    //Verifica a movimentação de acordo com a peça
    if (diferencaColuna == 2 && diferencaLinha == 1) {
        return true;
    }
    if (diferencaColuna == 1 && diferencaLinha == 2) {
        return true;
    }
    return false;
}
/* verificacoes:
        - Como ainda não conseguimos verificar as posições ocupadas, as peças podem atravessar outras peças por hora.
        -se a peça sai do tabuleiro
        - se ja existe uma peca na posicao desejada
        -se respeita as regras de movimento da peca
*/

//branco = 0 MAIUSCULO
//preto = 1 minusculo
void Cavalo::desenha() {
    if (cor == 1) {
        cout << "c";
    } else {
        cout << "C";
    }
}
