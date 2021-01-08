/*
Projeto: Jogo de Xadrez
3º Semestre de Ciências da Computação - UFSCar Sorocaba
Programação orientada a objetos
Profª Katti Faceli
Integrantes: Giovanni Alvarenga, Fábio Yamaya, João Victor Vilar
Implementação da classe "bispo"
Descrição:Implementa as funções da classe "bispo" contidas no arquivo .h
*/
#include <fstream>
#include <iostream>
#include "bispo.h"
#include "cavalo.h"
#include "jogo.h"
#include "peao.h"
#include "rainha.h"
#include "rei.h"
#include "torre.h"

using namespace std;

void verifiKatti(bool valido) {
    if (valido) {
        cout << "Movimento valido" << endl;
    } else {
        cout << "Movimento invalido" << endl;
    }
}

int main() {
    Jogo jogo1;
    //Printar jogadores:
    /*     Jogador* tempJog = jogo1.getJogador1();
    cout << "Jogador 1: ";
    tempJog->Jogador::printog();
    tempJog = jogo1.getJogador2();
    cout << "Jogador 2: ";
    tempJog->Jogador::printog(); */

    /*     Torre* torre = new Torre;
    Bispo* bispo = new Bispo;
    Cavalo* cavalo = new Cavalo;
    Rainha* rainha = new Rainha;
    Rei* rei = new Rei;
    Peao* peao = new Peao;
 */
    //Tabuleiro* tabuleiro = new Tabuleiro;
    /*     cout << "Tabuleiro:" << endl
         << endl;
    Tabuleiro* temp = jogo1.Jogo::getTabuleiro();
    temp->desenhar();
    cout << endl;

    jogo1.movimenta(6, 5, 5, 5); */

    /*
    cout << "Torre:" << endl;
    cout << "Teste para ver se o objeto foi criado:" << endl;
    torre->Torre::desenha();
    cout << "Tentativa valida de movimento" << endl;
    verifiKatti(torre->Torre::checaMovimento('a', 1, 'h', 1));
    cout << "Tentativa invalida de movimento" << endl;
    verifiKatti(torre->Torre::checaMovimento('a', 1, 'h', 2));
    cout << "----------------------------------------------------" << endl << endl;

    cout << "Bispo:" << endl;
    cout << "Teste para ver se o objeto foi criado:" << endl;
    bispo->Bispo::desenha();
    cout << "Tentativa valida de movimento" << endl;
    verifiKatti(bispo->Bispo::checaMovimento('a', 1, 'h', 8));
    cout << "Tentativa invalida de movimento" << endl;
    verifiKatti(bispo->Bispo::checaMovimento('c', 1, 'h', 1));
    cout << "----------------------------------------------------" << endl << endl;

    cout << "Cavalo:" << endl;
    cout << "Teste para ver se o objeto foi criado:" << endl;
    cavalo->Cavalo::desenha();
    cout << "Tentativa valida de movimento" << endl;
    verifiKatti(cavalo->Cavalo::checaMovimento('a', 1, 'c', 2));
    cout << "Tentativa invalida de movimento" << endl;
    verifiKatti(cavalo->Cavalo::checaMovimento('c', 1, 'h', 1));
    cout << "----------------------------------------------------" << endl << endl;

    cout << "Rainha:" << endl;
    cout << "Teste para ver se o objeto foi criado:" << endl;
    rainha->Rainha::desenha();
    cout << "Tentativa valida de movimento" << endl;
    verifiKatti(rainha->Rainha::checaMovimento('a', 1, 'c', 3));
    cout << "Tentativa invalida de movimento" << endl;
    verifiKatti(rainha->Rainha::checaMovimento('a', 1, 'c', 4));
    cout << "----------------------------------------------------" << endl << endl;

    cout << "Rei:" << endl;
    cout << "Teste para ver se o objeto foi criado:" << endl;
    rei->Rei::desenha();
    cout << "Tentativa valida de movimento" << endl;
    verifiKatti(rei->Rei::checaMovimento('a', 1, 'b', 2));
    cout << "Tentativa invalida de movimento" << endl;
    verifiKatti(rei->Rei::checaMovimento('a', 1, 'c', 4));
    cout << "----------------------------------------------------" << endl << endl;

    peao->setCor(0);
    cout << "Peao:" << endl;
    cout << "Teste para ver se o objeto foi criado:" << endl;
    peao->Peao::desenha();
    cout << "Tentativa valida de movimento" << endl;
    verifiKatti(peao->Peao::checaMovimento('a', 1, 'b', 1));
    cout << "Tentativa valida de movimento" << endl;
    verifiKatti(peao->Peao::checaMovimento('a', 1, 'd', 1));
    cout << "Tentativa valida de movimento" << endl;
    verifiKatti(peao->Peao::checaMovimento('a', 1, 'h', 3));
    cout << "Tentativa valida de movimento" << endl;
    verifiKatti(peao->Peao::checaMovimento('a', 1, 'k', 12));
    cout << "Tentativa invalida de movimento" << endl;
    verifiKatti(peao->Peao::checaMovimento('a', 1, 'c', 4));
    cout << "----------------------------------------------------" << endl << endl; */
}