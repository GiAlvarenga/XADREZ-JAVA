/*
Projeto: Jogo de Xadrez
3º Semestre de Ciências da Computação - UFSCar Sorocaba
Programação orientada a objetos
Profª Katti Faceli
Integrantes: Giovanni Alvarenga, Fábio Yamaya, João Victor Vilar
Implementação da classe "Tabuleiro"
Descrição:Implementa as funções da classe "Tabuleiro" contidas no arquivo .h
*/
#include "tabuleiro.h"

//Construtor da classe
Tabuleiro::Tabuleiro() {
    //posicoes = new Posicao[8][8];

    int flag = 1;
    //Cria o tabuleiro alternando as cores com uma matriz 8x8
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            //Usa a flag para saber quando é necessário alterar a cor
            if (flag == 1) {
                posicoes[i][j] = new Posicao(i, j, 0);
                flag = 0;
            } else {
                posicoes[i][j] = new Posicao(i, j, 1);
                flag = 1;
            }
        }
        if (flag == 1) {
            flag = 0;
        } else {
            flag = 1;
        }
    }
}

/* Posicao** getPosicao(){
    return posicoes;
} */

void Tabuleiro::setPeca(Peca* peca, int i, int j) {
    posicoes[i][j]->setPeca(peca);
}

//Função que desenha o tabuleiro no terminal
void Tabuleiro::desenhar() {
    cout << "  ";  // espaço para compensar o espaço usado para imprimir as linhas
    //imprime o número das colunas
    for (size_t i = 1; i <= 8; i++) {
        cout << "   " << i << "  ";
    }
    cout << endl;
    for (size_t i = 97; i < 105; i++) {
        for (size_t t = 0; t < 3; t++) {
            if (t == 1) {
                cout << (char)i << " ";
            } else {
                cout << "  ";
            }
            for (size_t j = 1; j <= 8; j++) {
                //Verifica se a posição está ocupada
                if (posicoes[i - 97][j - 1]->Posicao::estaOcupado() && t == 1) {
                    //Recebe a peça caso a posição esteja ocupada
                    Peca* temp = posicoes[i - 97][j - 1]->Posicao::getPeca();
                    if (posicoes[i - 97][j - 1]->Posicao::getCor()) {
                        cout << "\e[22;45m"
                             << "   ";
                        temp->desenha();
                        cout << "  "
                             << "\033[0m";
                    } else {
                        cout << "   ";
                        temp->desenha();
                        cout << "  ";
                    }
                    //temp->Peca::desenha(); faltou pois não há relação com a classe da peça específica
                } else {
                    if (posicoes[i - 97][j - 1]->Posicao::getCor()) {
                        cout << "\e[22;45m"
                             << "      "
                             << "\033[0m";
                    } else {
                        cout << "      ";
                    }
                }
            }
            cout << endl;
        }
    }
    cout << endl
         << endl
         << endl;
}

bool Tabuleiro::estaDentro(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    Peca* origem = posicoes[linhaOrigem][colunaOrigem]->getPeca();
    if (origem == NULL) {
        return false;
    }
    if (colunaOrigem >= 0 && colunaDestino >= 0 && colunaOrigem <= 7 && colunaDestino <= 7) {
        //cout << "Coluna esta dentro" << endl;
        if (linhaOrigem >= 0 && linhaDestino >= 0 && linhaOrigem <= 7 && linhaDestino <= 7) {
            //cout << "Linha esta dentro" << endl;
            if ((linhaOrigem != linhaDestino) || (colunaOrigem != colunaDestino)) {
                if (posicoes[linhaDestino][colunaDestino]->estaOcupado()) {
                    //cout << "Posicao destino esta ocupado" << endl;
                    Peca* destino = posicoes[linhaDestino][colunaDestino]->getPeca();
                    if (destino->getCor() != origem->getCor()) {
                        return true;
                    }
                } else {
                    //cout << "Posicao destino esta livre" << endl;
                    return true;
                }
            }
        }
    }
    return false;
}

bool Tabuleiro::caminhoLivre(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
    cout << linhaOrigem << colunaOrigem << " " << linhaDestino << colunaDestino << endl;
    Peca* peca = posicoes[linhaOrigem][colunaOrigem]->getPeca();
    char tipo = peca->getTipo();
    if (tipo == 'c' || tipo == 'C') {
        return true;
    }
    int cor = peca->getCor();
    if (linhaOrigem == linhaDestino) {
        if (colunaDestino > colunaOrigem) {
            for (size_t i = colunaOrigem + 1; i < colunaDestino; i++) {
                if (posicoes[linhaOrigem][i]->estaOcupado()) {
                    return false;
                }
            }
            return true;
        } else {
            for (size_t i = colunaOrigem - 1; i > colunaDestino; i--) {
                if (posicoes[linhaOrigem][i]->estaOcupado()) {
                    return false;
                }
            }
            return true;
        }
    }

    if (linhaDestino > linhaOrigem) {
        if (colunaOrigem == colunaDestino) {
            for (size_t i = linhaOrigem + 1; i < linhaDestino; i++) {
                if (posicoes[i][colunaOrigem]->estaOcupado()) {
                    //cout << "caminho obstruido" << endl;
                    return false;
                }
            }
            return true;
        } else {
            if (colunaDestino > colunaOrigem) {
                for (size_t i = linhaOrigem + 1, j = colunaOrigem + 1; i < linhaDestino; i++, j++) {
                    cout << linhaOrigem << " " << colunaOrigem << " // " << i << " " << j << endl;
                    if (posicoes[i][j]->estaOcupado()) {
                        //cout << "caminho obstruido" << endl;
                        return false;
                    }
                }
                return true;
            } else {
                for (size_t i = linhaOrigem + 1, j = colunaOrigem - 1; i < linhaDestino; i++, j--) {
                    if (posicoes[i][j]->estaOcupado()) {
                        //cout << "caminho obstruido" << endl;
                        return false;
                    }
                }
                return true;
            }
        }
    } else {
        if (colunaOrigem == colunaDestino) {
            for (size_t i = linhaOrigem - 1; i > linhaDestino; i--) {
                if (posicoes[i][colunaOrigem]->estaOcupado()) {
                    //cout << "caminho obstruido" << endl;
                    return false;
                }
            }
            return true;
        } else {
            if (colunaDestino > colunaOrigem) {
                for (size_t i = linhaOrigem - 1, j = colunaOrigem + 1; i > linhaDestino; i--, j++) {
                    if (posicoes[i][j]->estaOcupado()) {
                        //cout << "caminho obstruido" << endl;
                        return false;
                    }
                }
                return true;
            } else {
                for (size_t i = linhaOrigem - 1, j = colunaOrigem - 1; i > linhaDestino; i--, j--) {
                    if (posicoes[i][j]->estaOcupado()) {
                        return false;
                    }
                }
                return true;
            }
        }
    }
}

Peca* Tabuleiro::getPeca(int linha, int coluna) {
    return posicoes[linha][coluna]->getPeca();
}