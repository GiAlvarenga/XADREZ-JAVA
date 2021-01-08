/*
Projeto: Jogo de Xadrez
3º Semestre de Ciências da Computação - UFSCar Sorocaba
Programação orientada a objetos
Profª Katti Faceli
Descrição:Definição da classe "posicao" que mantém as informações referente a todas as possíveis posições do tabuleiro
*/
#ifndef posicao_h
#define posicao_h
#include "peca.h"
#include"peao.h"
#include"bispo.h"
#include"rei.h"
#include"cavalo.h"
#include"rainha.h"
#include"torre.h"

using namespace std;

class Posicao{

    private:    
        const int cor;
        char linha;
        int coluna;
        Peca* peca;

    public:
        //Construtor para cada posição do jogo, com sua cor, linha e coluna
        Posicao(char _linha, int _coluna, int _cor);
        //Destrutor
        ~Posicao();
        //Altera peça
        void setPeca(Peca* p);
        //Destrutor
        Peca* getPeca();
        int getCor();
        //Verifica se está ocupado
        bool estaOcupado();        
};

#endif