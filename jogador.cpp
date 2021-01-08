/*
Projeto: Jogo de Xadrez
3º Semestre de Ciências da Computação - UFSCar Sorocaba
Programação orientada a objetos
Profª Katti Faceli
Integrantes: Giovanni Alvarenga, Fábio Yamaya, João Victor Vilar
Implementação da classe "jogador"
Descrição:Implementa as funções da classe "jogador" contidas no arquivo .h
*/
#include "jogador.h"
#include <string>

using namespace std;

//Construtor da classe ( ainda não utilizado )
Jogador::Jogador(string _nome, int _cor) : cor(_cor) {
    nome = _nome;
}

Jogador::~Jogador() {
    free(pecasAtivas);
}

//Imprime na tela o nome dos jogadores
void Jogador::printog() {
    cout << nome << endl;
}

Peca** Jogador::getPecasAtivas() {
    return pecasAtivas;
}
