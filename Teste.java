import java.util.Scanner; // Import the Scanner class
import Bispo.java;
import Tabuleiro.java;
import Jogo.java;
import Rei.java;
import Peao.java;
import Torre.java;
import Rainha.java;

 public class Teste {
  public static void main(String[] args) {
    //muda a cor da area de impressão
    System.out.print("\033[100m");
    //Cria os objetos Jogo, Tabuleiro, Posições, Jogador e Peças, tanto Brancas quanto Pretas.
    Bispo bispo1 = new Bispo(1);
    Bispo bispo2 = new Bispo(0);
    Rei rei1 = new Rei(0);
    Rei rei2 = new Rei(1);
    Cavalo cavalo1 = new Cavalo(1);
    Cavalo cavalo2 = new Cavalo(0);
    Peao peao1 = new Peao(0);
    Peao peao2 = new Peao(1);
    Torre torre1 = new Torre(1);
    Torre torre2 = new Torre(0);
    Rainha rainha1 = new Rainha(1);
    Rainha rainha2 = new Rainha(0);
    
    Jogo jogo1 = new Jogo();
    //Desenha o Tabuleiro
    jogo1.desenhaTabuleiro();
    
    //Imprime o nome dos jogadores
    jogo1.getJogador1().imprimir();
    jogo1.getJogador2().imprimir();
    
    //Verifica se o destino de um movimento qualquer esta dentro dos limites do tabuleiro
    jogo1.getTabuleiro1().checaMovimento(0, 10);
    jogo1.getTabuleiro1().checaMovimento(-1, 5);
    jogo1.getTabuleiro1().checaMovimento(0, 4);
    jogo1.getTabuleiro1().checaMovimento(0, 2);

    //Valida o Bispo
    bispo1.desenha();
    bispo2.desenha();
    bispo1.checaMovimento(0, 3, 6, 8, false);
    bispo2.checaMovimento(0, 3, 6, 4, false);
    bispo2.checaMovimento(0, 3, 0, 4, false);
    bispo2.checaMovimento(0, 3, 1, 3, false);
    bispo2.checaMovimento(0, 3, 1, 4, false);

    //Valida o Rei
    rei1.desenha();
    rei2.desenha();
    rei1.checaMovimento(0, 3, 6, 8, false);
    rei2.checaMovimento(0, 3, 6, 4, false);
    rei1.checaMovimento(0, 3, 0, 4, false);
    rei2.checaMovimento(0, 3, 1, 3, false);
    rei1.checaMovimento(0, 3, 1, 4, false);

    //Valida o Cavalo
    cavalo1.desenha();
    cavalo2.desenha();
    cavalo1.checaMovimento(0, 3, 6, 8, false);
    cavalo2.checaMovimento(0, 3, 6, 4, false);
    cavalo1.checaMovimento(0, 3, 0, 4, false);
    cavalo2.checaMovimento(0, 3, 2, 4, false);
    cavalo1.checaMovimento(0, 3, 1, 5, false);

    //Valida o Peao
    peao1.desenha();
    peao2.desenha();
    peao2.checaMovimento(0, 3, 2, 3, false);//anda 2 casas para frente (baixo p cima)
    peao1.checaMovimento(4, 3, 2, 3, false);//anda 2 casas para frente (cima p baixo)
    peao2.checaMovimento(0, 3, 2, 3, false);//anda 2 casas para frente (baixo p cima)
    peao1.checaMovimento(4, 3, 2, 3, false);//anda 2 casas para frente (cima p baixo)
    peao1.checaMovimento(4, 4, 3, 4, false);//anda 1 casa para frente (cima p baixo)
    peao2.checaMovimento(4, 4, 5, 4, false);//anda 1 casa para frente (baixo p cima)
    peao2.checaMovimento(4, 4, 5, 5, true);//come na diagonal
    peao2.checaMovimento(4, 4, 5, 3, true);//come na diagonal
    peao1.checaMovimento(4, 4, 3, 5, true);//come na diagonal
    peao1.checaMovimento(4, 4, 3, 3, true);//come na diagonal
    peao2.checaMovimento(0, 3, 1, 3, false);
    peao1.checaMovimento(0, 3, 1, 4, false);
    peao1.checaMovimento(0, 2, 0, 4, false);
    peao1.checaMovimento(0, 2, 0, 4, true);
    peao2.checaMovimento(0, 2, 0, 4, false);
    peao2.checaMovimento(0, 2, 0, 4, true);
    peao1.checaMovimento(0, 2, 1, 3, false);
    peao1.checaMovimento(0, 2, 1, 3, true);
    peao1.checaMovimento(0, 2, 1, 3, false);
    
    //Valida a Torre
    torre1.desenha();
    torre2.desenha();
    torre1.checaMovimento(0, 3, 0, 7, false); //move em linha
    torre2.checaMovimento(0, 3, 6, 3, false); //move em coluna
    torre1.checaMovimento(0, 3, 0, 4, false);
    torre2.checaMovimento(0, 3, 1, 3, false);
    torre1.checaMovimento(0, 3, 1, 4, false);

    //Valida a Rainha
    rainha1.desenha();
    rainha2.desenha();
    rainha1.checaMovimento(0, 3, 6, 8, false);
    rainha2.checaMovimento(0, 3, 6, 4, false);
    rainha1.checaMovimento(0, 3, 0, 7, false); //move em linha
    rainha2.checaMovimento(0, 3, 6, 3, false); //move em coluna
    rainha1.checaMovimento(0, 3, 0, 4, false);
    rainha2.checaMovimento(0, 3, 1, 3, false);
    rainha1.checaMovimento(0, 3, 1, 4, false);

  }
} 



