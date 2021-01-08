import java.util.Scanner; // Import the Scanner class
import Jogador.java;
import Tabuleiro.java;

public class Jogo{
    private Tabuleiro tabuleiro1;
    private Jogador jogador1;
    private Jogador jogador2;

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




