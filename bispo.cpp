/*
Projeto: Jogo de Xadrez
3º Semestre de Ciências da Computação - UFSCar Sorocaba
Programação orientada a objetos
Profª Katti Faceli
Integrantes: Giovanni Alvarenga, Fábio Yamaya, João Victor Vilar
Implementação da classe "bispo"
Descrição:Implementa as funções da classe "bispo" contidas no arquivo .h
*/
#include "bispo.h"

//Construtor da classe ( ainda não utilizado )
Bispo::Bispo(int _cor, char _tipo) : Peca(_cor, _tipo) {}

//Destrutor da classe bispo ( ainda não utilizado )
//Bispo::~Bispo(){}

//Verifica se o movimento da peça está correto
bool Bispo::checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    //Calcula a diferença entre linha e coluna para obter o movimento
    int diferencaLinha = linhaDestino - linhaOrigem;
    int diferencaColuna = colunaDestino - colunaOrigem;
    //Verifica a movimentação de acordo com a peça
    if (diferencaColuna == diferencaLinha || diferencaColuna == -diferencaLinha) {
        return true;
    }
    //cout << "movimento invalido " << linhaOrigem << colunaOrigem << " " << linhaDestino << colunaDestino << endl;
    return false;
}
/* verificacoes:
        -se a peça sai do tabuleiro
        - se ja existe uma peca na posicao desejada
        -se respeita as regras de movimento da peca
*/

//branco = 0 MAIUSCULO
//preto = 1 minusculo
void Bispo::desenha() {
    if (cor == 1) {
        cout << "b";
    } else {
        cout << "B";
    }
}
