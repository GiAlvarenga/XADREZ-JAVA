/*
Projeto: Jogo de Xadrez
3º Semestre de Ciências da Computação - UFSCar Sorocaba
Programação orientada a objetos
Profª Katti Faceli
Integrantes: Giovanni Alvarenga, Fábio Yamaya, João Victor Vilar
Implementação da classe "posicao"
Descrição:Implementa as funções da classe "posicao" contidas no arquivo .h
*/
#include "posicao.h"

using namespace std;

//Construtor da classe
Posicao::Posicao(char _linha, int _coluna, int _cor) : cor(_cor){
    linha = _linha;
    coluna = _coluna;
    peca = NULL;
}

//Destrutor da classe
Posicao::~Posicao(){

}

//Modifica peca devido ao escopo privado
void Posicao::setPeca(Peca* p){
    peca = p;
}

//Retorna peca devido ao escopo privado
Peca* Posicao::getPeca(){
    return peca;
}

//Retorna a cor devido ao escopo privado
int Posicao::getCor(){
    return cor;
}

//Retorna um valor booleano para saber se uma posição está ocupada ou não
bool Posicao::estaOcupado(){
    if(peca != NULL){
        return true;
    } else {
        return false;
    }
}