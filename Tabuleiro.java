import Posicao.java;

public class Tabuleiro {
    private Posicao[][] posicoes;
    //Armazenado como uma matriz de posicoes
    public Tabuleiro() {
        int flag = 1; //Utilizado para alternar as cores do tabuleiro
        posicoes = new Posicao[8][8];
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
            }//muda o flag para garantir que ao mudar de linha, a nova casa terá uma cor diferente.
            if (flag == 1) {
                flag = 0;
            } else {
                flag = 1;
            }
        }
    }

    public void desenhar() {
        System.out.print("  ");// espaço para compensar o espaço usado para imprimir as linhas
        int i, j,t;
        //imprime o número das colunas
        for (i = 1; i <= 8; i++) {
            System.out.print("   "+ i + "  ");
        }
        System.out.println();
        //Imprime as letras que indicam as linhas
        for (i = 97; i < 105; i++) {
            for (t = 0; t < 3; t++) {
                if (t == 1) {
                    char lin = (char)i;
                    System.out.print(lin+" ");
                } else {
                    System.out.print("  ");
                }
                for (j = 1; j <= 8; j++) {
                    //ver se tem peça na posição
                    if((posicoes[i - 97][j - 1].getOcupado())&&(t==1)){
                        if (posicoes[i - 97][j - 1].getCor()==1) {                        
                            System.out.print("\033[107m"+"  ");
                            posicoes[i-97][j-1].getPeca().desenha();
                            System.out.print("   "+"\033[100m");//6 espaços
                        }
                        else {
                            System.out.print("\033[101m"+"  ");
                            posicoes[i-97][j-1].getPeca().desenha();
                            System.out.print("   "+"\033[100m");
                        }
                    }
                    else{
                        if (posicoes[i - 97][j - 1].getCor()==1) {                        
                            System.out.print("\033[107m"+"      "+"\033[100m");//6 espaços
                        } else {
                            System.out.print("\033[101m"+"      "+"\033[100m");
                        }
                    }
                }
                System.out.println();
            }
        }
        System.out.println();
        System.out.println();
        System.out.println();
    }
    //Verifica se o Movimento esta dentro do tabuleiro
    public boolean checaMovimento(int linha, int coluna){
        if((linha >= 0 && linha < 8)&&(coluna >= 0 && coluna < 8) ){
            System.out.println("Movimento Válido");
            return true;
        }
        System.out.println("Movimento Inválido");
        return false;
    }

    public void setPeca(Peca peca,int i ,int j)
    {
        posicoes[i][j].setPeca(peca);
        posicoes[i][j].setOcupado();
    }
 
}




