/*
Projeto: Jogo de Xadrez
3º Semestre de Ciências da Computação - UFSCar Sorocaba
Programação orientada a objetos
Profª Katti Faceli
Integrantes: Giovanni Alvarenga, Fábio Yamaya, João Victor Vilar
Implementação da classe "peao"
Descrição:Implementa as funções da classe "peao" contidas no arquivo .h
*/
#include "peao.h"

//Construtor da classe
Peao::Peao(int _cor, char _tipo) : Peca(_cor, _tipo) {}

//Destrutor da classe
//Peao::~Peao(){}

bool Peao::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, bool haPeca) {
    //Calcula a diferença entre linha e coluna para obter o movimento
    int diferencaLinha = linhaDestino - linhaOrigem;
    int diferencaColuna = colunaDestino - colunaOrigem;
    //cout << "função do peao" << endl;
    //Verifica a movimentação de acordo com a peça
    if (haPeca == 0) {
        if (jaMoveu) {
            if (cor == 1 && diferencaLinha == 1 && diferencaColuna == 0) {
                return true;
            } else if (cor == 0 && diferencaLinha == -1 && diferencaColuna == 0) {
                return true;
            }
        } else {
            jaMoveu = 1;
            if (cor == 1 && (diferencaLinha == 1 || diferencaLinha == 2) && diferencaColuna == 0) {
                return true;
            }
            if (cor == 0 && (diferencaLinha == -1 || diferencaLinha == -2) && diferencaColuna == 0) {
                return true;
            }
        }
        return false;
    } else {
        if (colunaOrigem == colunaDestino) {
            return false;
        }

        if (diferencaColuna == 1 || diferencaColuna == -1) {
            if (cor == 1 && diferencaLinha == 1) {
                return true;
            } else if (cor == 0 && diferencaLinha == -1) {
                return true;
            }
        }
        return false;
    }
}
/* verificacoes:
        - Preto sempre começa em cima
        -se a peça sai do tabuleiro
        - se ja existe uma peca na posicao desejada
        -se respeita as regras de movimento da peca
*/

//branco = 0 MAIUSCULO
//preto = 1 minusculo
void Peao::desenha() {
    if (cor == 1) {
        cout << "p";
    } else {
        cout << "P";
    }
}