/*
Projeto: Jogo de Xadrez
3º Semestre de Ciências da Computação - UFSCar Sorocaba
Programação orientada a objetos
Profª Katti Faceli
Integrantes: Giovanni Alvarenga, Fábio Yamaya, João Victor Vilar
Implementação da classe "jogo"
Descrição:Implementa as funções da classe "jogo" contidas no arquivo .h
*/

//############################################### COR 1 COMEÇA EM CIMA ##############################################
#include "jogo.h"
#include <fstream>
#include <string>

#include "tabuleiro.h"

using namespace std;

//Construtor da classe ( ainda não utilizado )
Jogo::Jogo() {
    string nomeJogador;
    cout << "----Jogo de Xadrez----" << endl;
    cout << "Digite o nome do Jogador 1:" << endl;
    cin >> nomeJogador;
    jogador1 = new Jogador(nomeJogador, 0);
    cout << "Digite o nome do Jogador 2:" << endl;
    cin >> nomeJogador;
    jogador2 = new Jogador(nomeJogador, 1);

    tabuleiro1 = new Tabuleiro();

    //de 0 a 7, peão
    //em seguida, duplica a ordem natural dos rapazes
    //torre,torre,cavalo,cavalo,
    for (int i = 0; i < 8; i++) {
        pecasBrancas[i] = new Peao(0, 'P');
        pecasPretas[i] = new Peao(1, 'p');
    }

    pecasBrancas[8] = new Torre(0, 'T');
    pecasBrancas[15] = new Torre(0, 'T');
    pecasBrancas[9] = new Cavalo(0, 'C');
    pecasBrancas[14] = new Cavalo(0, 'C');
    pecasBrancas[10] = new Bispo(0, 'B');
    pecasBrancas[13] = new Bispo(0, 'B');
    pecasBrancas[11] = new Rei(0, 'K');
    pecasBrancas[12] = new Rainha(0, 'Q');

    pecasPretas[8] = new Torre(1, 't');
    pecasPretas[15] = new Torre(1, 't');
    pecasPretas[9] = new Cavalo(1, 'c');
    pecasPretas[14] = new Cavalo(1, 'c');
    pecasPretas[10] = new Bispo(1, 'b');
    pecasPretas[13] = new Bispo(1, 'b');
    pecasPretas[11] = new Rei(1, 'k');
    pecasPretas[12] = new Rainha(1, 'q');

    Peca** pecasAtivas1 = jogador1->getPecasAtivas();
    Peca** pecasAtivas2 = jogador2->getPecasAtivas();

    for (size_t i = 0; i < 16; i++) {
        pecasAtivas1[i] = pecasBrancas[i];
        pecasAtivas2[i] = pecasPretas[i];
    }

    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 7; j++) {
            if (i == 1) {
                tabuleiro1->setPeca(pecasPretas[j], i, j);
                tabuleiro1->setPeca(pecasBrancas[j], 6, j);
            }
            if (i == 0) {
                tabuleiro1->setPeca(pecasPretas[j + 8], i, j);
                tabuleiro1->setPeca(pecasBrancas[j + 8], 7, j);
            }
        }
    }

    turnos();
}
//Imprime o início do jogo, recebe os nomes dos jogadores e cria um objeto tabuleiro
/* void Jogo::inicializar (){

}  */

//Função get para obter o objeto tabuleiro devido à restrição de escopo e ausência de herança
Tabuleiro* Jogo::getTabuleiro() {
    return tabuleiro1;
}

//Função get para obter o objeto Jogador devido à restrição de escopo e ausência de herança
Jogador* Jogo::getJogador1() {
    return jogador1;
}

//Função get para obter o objeto Jogador devido à restrição de escopo e ausência de herança
Jogador* Jogo::getJogador2() {
    return jogador2;
}

void Jogo::turnos() {
    int turno = 0;
    int acabou = 0;
    int lO, cO, lD, cD;
    int sair = 0;
    char continuar;
    fstream arq;

    tabuleiro1->desenhar();
    cout << "Deseja continuar o último jogo? <S/N>" << endl;
    cin >> continuar;

    if (continuar == 'S') {
        arq.open("save.txt");
        while (arq) {
            arq >> lO;
            arq >> cO;
            arq >> lD;
            arq >> cD;
            if (!arq) {
                break;
            }
            movimenta(lO, cO, lD, cD);
            turno = !turno;
            cout << "turno" << turno << endl;
        }
        arq.close();
        arq.open("save.txt", ios::in | ios::out | ios::ate);
    } else {
        arq.open("save.txt", fstream::in | fstream::out | fstream::trunc);
        /*             if (remove("save.txt") != 0)
                perror("Error deleting file"); */
    }
    tabuleiro1->desenhar();
    //arq.open("save.txt");

    while (!acabou) {
        /* cout << "deseja Sair do jogo? <1/0>" << endl;
        cin >> sair;
        if (sair == 1) {
            arq.close();
            return;
        } */
        cout << "Jogador " << turno + 1 << " Insira seu movimento < Sair: -1 >" << endl;

        cin >> lO;
        if (lO == -1) {
            return;
        }
        cin >> cO;
        cin >> lD;
        cin >> cD;

        Peca* temp = tabuleiro1->getPeca(lO, cO);
        while (temp == NULL || temp->getCor() != turno || !movimenta(lO, cO, lD, cD)) {
            cout << "Movimento inválido, insira outro movimento" << endl;
            cin >> lO;
            if (lO == -1) {
                return;
            }
            cin >> cO;
            cin >> lD;
            cin >> cD;
            temp = tabuleiro1->getPeca(lO, cO);
        }
        arq << lO << endl;
        arq << cO << endl;
        arq << lD << endl;
        arq << cD << endl;

        tabuleiro1->desenhar();
        if (estaEmXeque(turno)) {
            cout << "jogador " << !turno + 1 << " esta em Xeque" << endl;
        }
        if (estaEmXequeMate(turno)) {
            cout << "xxxxxxxxxxxxxxxxx Xeque Mate xxxxxxxxxxxxxxxxx" << endl;
            cout << "Jogador " << turno + 1 << " venceu o jogo!" << endl;
            acabou = 1;
        }
        turno = !turno;
    }
    arq.close();
}

bool Jogo::movimentoValido(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    Peca* origem = tabuleiro1->getPeca(linhaOrigem, colunaOrigem);
    Peca* destino = tabuleiro1->getPeca(linhaDestino, colunaDestino);
    if (origem == NULL) {
        return false;
    }
    if (tabuleiro1->estaDentro(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino)) {
        if (origem->getTipo() == 'p' || origem->getTipo() == 'P') {
            if (destino != NULL) {
                if (origem->checaMovimento(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino, 1)) {
                    return true;
                }
            } else {
                if (origem->checaMovimento(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino, 0)) {
                    return true;
                }
            }
        } else if (origem->getTipo() == 'k') {
            if (verificaXeque(linhaDestino, colunaDestino, 0)) {
                return false;
            } else {
                if (origem->checaMovimento(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino)) {
                    if (tabuleiro1->caminhoLivre(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino)) {
                        return true;
                    }
                }
            }
        } else if (origem->getTipo() == 'K') {
            if (verificaXeque(linhaDestino, colunaDestino, 1)) {
                return false;
            } else {
                if (origem->checaMovimento(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino)) {
                    if (tabuleiro1->caminhoLivre(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino)) {
                        return true;
                    }
                }
            }
        } else {
            if (origem->checaMovimento(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino)) {
                if (tabuleiro1->caminhoLivre(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino)) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Jogo::movimenta(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    Peca* origem = tabuleiro1->getPeca(linhaOrigem, colunaOrigem);
    Peca* destino = tabuleiro1->getPeca(linhaDestino, colunaDestino);
    if (movimentoValido(linhaOrigem, colunaOrigem, linhaDestino, colunaDestino)) {
        /*         cout << "entrei em aqui" << endl;
        tabuleiro1->setPeca(NULL, linhaOrigem, colunaOrigem);
        tabuleiro1->setPeca(origem, linhaDestino, linhaDestino);
        if (estaEmXeque(!origem->getCor())) {
            cout << "entrei ali" << endl;
            tabuleiro1->setPeca(origem, linhaOrigem, colunaOrigem);
            tabuleiro1->setPeca(destino, linhaDestino, linhaDestino);
            return false;
        } else {
            tabuleiro1->setPeca(origem, linhaOrigem, colunaOrigem);
            tabuleiro1->setPeca(destino, linhaDestino, linhaDestino);
        } */
        if (destino != NULL) {
            int corOrigem = origem->getCor();
            int corDestino = destino->getCor();
            if (corDestino != corOrigem) {
                Peca** pecasAtivas;
                if (origem->getCor() == 0) {
                    pecasAtivas = jogador2->getPecasAtivas();
                } else {
                    pecasAtivas = jogador1->getPecasAtivas();
                }
                for (size_t i = 0; i < 16; i++) {
                    if (destino == pecasAtivas[i]) {
                        pecasAtivas[i] = NULL;
                    }
                }
            }
        }
        tabuleiro1->setPeca(NULL, linhaOrigem, colunaOrigem);
        tabuleiro1->setPeca(origem, linhaDestino, colunaDestino);
        return true;
    }
    return false;
}

bool Jogo::estaEmXeque(int cor) {
    int posicaoRei[2];
    Jogo::achaRei(cor, posicaoRei);
    return Jogo::verificaXeque(posicaoRei[0], posicaoRei[1], cor);
}

void Jogo::achaRei(int cor, int posicaoRei[]) {
    int iRei, jRei;
    bool achou = 0;
    char tipo = ' ';
    for (iRei = 0; iRei < 8 && !achou; iRei++) {
        if (!cor) {
            for (jRei = 0; jRei < 8 && !achou; jRei++) {
                Peca* rei = tabuleiro1->getPeca(iRei, jRei);
                if (rei) {
                    tipo = rei->getTipo();
                    if (tipo == 'k') {
                        achou = 1;
                    }
                }
            }
        } else {
            for (jRei = 0; jRei < 8 && !achou; jRei++) {
                Peca* rei = tabuleiro1->getPeca(iRei, jRei);
                if (rei) {
                    tipo = rei->getTipo();
                    if (tipo == 'K') {
                        achou = 1;
                    }
                }
            }
            if (jRei == 8) {
                //cout << "Rei não encontrado" << endl;
            }
        }
    }

    posicaoRei[0] = iRei - 1;
    posicaoRei[1] = jRei - 1;

    return;
}

bool Jogo::verificaXeque(int iRei, int jRei, int cor) {
    Peca* atual;
    //cout << "verificando se " << iRei << " " << jRei << " esta em cheque" << endl;

    Peca* rei = tabuleiro1->getPeca(iRei, jRei);
    tabuleiro1->setPeca(NULL, iRei, jRei);

    for (size_t i = 0; i < 8; i++) {
        for (size_t j = 0; j < 8; j++) {
            //cout << i << j << endl;
            atual = tabuleiro1->getPeca(i, j);
            if (atual != NULL) {
                if (atual->getCor() == cor) {
                    if (atual->getTipo() != 'k' && atual->getTipo() != 'K') {
                        //cout << "veriricando movimento valido de " << i << j << " para " << iRei << jRei << endl;
                        if (Jogo::movimentoValido(i, j, iRei, jRei)) {
                            //cout << "esta em cheque" << endl;
                            tabuleiro1->setPeca(rei, iRei, jRei);
                            return true;
                        }
                    } /*  else {
                        if (atual->checaMovimento(i, j, iRei, jRei)) {
                            if (tabuleiro1->caminhoLivre(i, j, iRei, jRei)) {
                                tabuleiro1->setPeca(rei, iRei, jRei);
                                return true;
                            }
                        }
                    } */
                }
            }
        }
    }
    //cout << "nao esta em cheque" << endl;
    tabuleiro1->setPeca(rei, iRei, jRei);
    return false;
}

bool Jogo::estaEmXequeMate(int cor) {
    int posicaoRei[2];
    Jogo::achaRei(cor, posicaoRei);
    //cout << "Posicao do rei: " << posicaoRei[0] << " " << posicaoRei[1] << endl;
    if (!Jogo::verificaXeque(posicaoRei[0], posicaoRei[1], cor)) {
        return false;
    }
    int i = posicaoRei[0] - 1;
    int j = posicaoRei[1] - 1;
    //cout << "Começando verificação em: " << i << " " << j << endl;
    for (; i <= posicaoRei[0] + 1; i++) {
        j = posicaoRei[1] - 1;
        for (; j <= posicaoRei[1] + 1; j++) {
            //cout << "Verificando se a posicao " << i << " " << j << " é válida" << endl;
            if (i >= 0 && i <= 7 && j >= 0 && j <= 7) {
                if (Jogo::movimentoValido(posicaoRei[0], posicaoRei[1], i, j)) {
                    return false;
                }
            }
        }
    }

    int iAmeacas[16];
    int jAmeacas[16];
    int nAmeacas = 0;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (Jogo::movimentoValido(i, j, posicaoRei[0], posicaoRei[1])) {
                //cout << "Ameaça da posicao: " << i << " " << j << endl;
                iAmeacas[nAmeacas] = i;
                jAmeacas[nAmeacas] = j;
                nAmeacas++;
            }
        }
    }
    for (size_t ameaca = 0; ameaca < nAmeacas; ameaca++) {
        while ((iAmeacas[ameaca] != posicaoRei[0]) && (jAmeacas[ameaca] != posicaoRei[1])) {
            for (size_t linha = 0; linha < 8; linha++) {
                for (size_t coluna = 0; coluna < 8; coluna++) {
                    //cout << "VErificando se peca " << linha << coluna << " consegue se mover para" << iAmeacas[ameaca] << jAmeacas[ameaca] << endl;
                    Peca* temp = tabuleiro1->getPeca(linha, coluna);
                    if (temp != NULL && (temp->getCor()) != cor) {
                        if (Jogo::movimentoValido(linha, coluna, iAmeacas[ameaca], jAmeacas[ameaca])) {
                            //cout << "peca da posicao " << linha << " " << coluna << " consegue bloquear/capturar ameaça" << endl;
                            Peca* bloqueador = tabuleiro1->getPeca(linha, coluna);
                            Peca* bloqueio = tabuleiro1->getPeca(iAmeacas[ameaca], jAmeacas[ameaca]);
                            tabuleiro1->setPeca(bloqueador, iAmeacas[ameaca], jAmeacas[ameaca]);
                            if (!verificaXeque(posicaoRei[0], posicaoRei[1], cor)) {
                                return false;
                            }
                            tabuleiro1->setPeca(bloqueador, linha, coluna);
                            tabuleiro1->setPeca(bloqueio, iAmeacas[ameaca], jAmeacas[ameaca]);
                        }
                    }
                }
            }
            if (iAmeacas[ameaca] > posicaoRei[0]) {
                iAmeacas[ameaca]--;
            } else if (iAmeacas[ameaca] < posicaoRei[0]) {
                iAmeacas[ameaca]++;
            }
            if (jAmeacas[ameaca] > posicaoRei[1]) {
                jAmeacas[ameaca]--;
            } else if (jAmeacas[ameaca] < posicaoRei[1]) {
                jAmeacas[ameaca]++;
            }
        }
    }
    return true;
}

Jogo::~Jogo() {
}
/* primeiro verificar se rei esta em xeque para todos os 8
quadrados em seu redor E para o quadrado q ele está (posições no total) 

Na verificação de xeque guardar as posições de todas as peças q colocam ele em xeque (ameaça)

Para cada ameaça, verificar para cada quadrado q está entre a ameaça e o rei (incluindo a própria
ameaça, pois se alguma peça conseguir comer a ameaça, o rei não está em xeque mate),
se é possível mover alguma peça (incluindo o proprio rei) do outro jogador para esse quadrado
(bloquear ou anular a ameaça)*/