import java.lang.Math;

public class Cavalo {
    private final int cor;// poderia ser boolean mas prefiro trabalhar com INT e futuramente sera um
                   // atributo da classepeca
    private boolean estado; // 1 para peças ativas, 0 para peças inativas, será utilizado futuramente

    public Cavalo(int _cor) {
        this.cor = _cor;
        this.estado = true;
    }

    public boolean checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
        //Verifica somente se o movimento da peça é valido, sem considerar os limetes do tabuleiro, verificado pela classe Tabuleiro
        int diferencaLinha = Math.abs(linhaDestino - linhaOrigem);
        int diferencaColuna = Math.abs(colunaDestino - colunaOrigem);
        
        //Verifica se o movimento esta de acordo com as regras
        if (diferencaColuna == 2 && diferencaLinha == 1) {
            System.out.println("Movimento valido para Cavalo: "+linhaOrigem+","+colunaOrigem+"->"+linhaDestino+","+colunaDestino);
            return true;
        }
        if (diferencaColuna == 1 && diferencaLinha == 2) {
            System.out.println("Movimento valido para Cavalo: "+linhaOrigem+","+colunaOrigem+"->"+linhaDestino+","+colunaDestino);
            return true;
        }
        System.out.println("Movimento invalido para Cavalo: "+linhaOrigem+","+colunaOrigem+"->"+linhaDestino+","+colunaDestino);
        return false;
    }
    //desenha o cavalo
    public void desenha(){
        if (cor == 1) {
            System.out.println("c");
        } else { 
            System.out.println("C");
        }
    }
    
}




