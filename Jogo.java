import java.util.Scanner; // Import the Scanner class
import Jogador.java;
import Tabuleiro.java;

public class Jogo{
    private Tabuleiro tabuleiro1;
    private Jogador jogador1;
    private Jogador jogador2;
    private Peca pecas1[];
    private Peca pecas2[];
    private int turno;

    public Jogo(){
        String aux;
        //le o nome dos jogadores
        Scanner myObj = new Scanner(System.in);
        System.out.println("---------------Jogo de Xadrez---------------");
        System.out.println("Digite o nome do Jogador 1:");
        aux = myObj.nextLine();
        this.jogador1 = new Jogador(aux , 0);
        System.out.println("Digite o nome do Jogador 2:");
        aux = myObj.nextLine();
        this.jogador2 = new Jogador(aux , 1); 
        //inicia o tabuleiro
        tabuleiro1 = new Tabuleiro();
        
        pecas1 = new Peca[16];
        pecas2 = new Peca[16];

        for (int i = 0; i < 8; i++) {
            pecas1[i] = new Peao(0);
            pecas2[i] = new Peao(1);
        }
    
        

        pecas1[8] = new Torre(0);
        pecas1[15] = new Torre(0);
        pecas1[9] = new Cavalo(0);
        pecas1[14] = new Cavalo(0);
        pecas1[10] = new Bispo(0);
        pecas1[13] = new Bispo(0);
        pecas1[11] = new Rei(0);
        pecas1[12] = new Rainha(0);
    
        pecas2[8] = new Torre(1);
        pecas2[15] = new Torre(1);
        pecas2[9] = new Cavalo(1);
        pecas2[14] = new Cavalo(1);
        pecas2[10] = new Bispo(1);
        pecas2[13] = new Bispo(1);
        pecas2[11] = new Rei(1);
        pecas2[12] = new Rainha(1);
    
        for (int i = 0; i <= 1; i++) {
            for (int j = 0; j <= 7; j++) {
                if (i == 1) {
                    tabuleiro1.setPeca(pecas2[j], i, j);
                    tabuleiro1.setPeca(pecas1[j], 6, j);
                }
                if (i == 0) {
                    tabuleiro1.setPeca(pecas2[j + 8], i, j);
                    tabuleiro1.setPeca(pecas1[j + 8], 7, j);
                }
            }
        }

    }
   
    //chama a funcao que imprime o tabuleiro
    public void desenhaTabuleiro(){        
        this.tabuleiro1.desenhar();
    }
    //getters 
    public Jogador getJogador1() {
        return jogador1;
    }

    public Jogador getJogador2() {
        return jogador2;
    }
    
    public Tabuleiro getTabuleiro1() {
        return tabuleiro1;
    }
}




