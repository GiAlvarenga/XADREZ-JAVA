/*
Projeto: Jogo de Xadrez
3º Semestre de Ciências da Computação - UFSCar Sorocaba
Programação orientada a objetos
Profª Katti Faceli
Descrição:Definição da classe "peca" que irá conter as informações não específicas de peça, como sua posição e se está presente
*/
#ifndef peca_h
#define peca_h
#include <iostream>

using namespace std;

class Peca {
   private:
    /*         char linha;
        int coluna; */
    //Se a peça já foi capturada
    bool capturado;

   protected:
    const int cor;
    char tipo;

   public:
    Peca(int _cor, char _tipo);
    //Construtor
    //Peca(int _cor, char _linha, int _coluna);
    //Destrutor
    char getTipo();
    int getCor();
    virtual void desenha();
    ~Peca();
    virtual bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino);
    virtual bool checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, bool haPeca);
};
#endif