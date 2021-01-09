public class Bispo extends Peca{

    public Bispo(int _cor) {
        this.cor = _cor;
        this.estado = true;
    }

    public boolean checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, boolean haPeca) {
        if ((linhaDestino == linhaOrigem) &&(colunaDestino == colunaOrigem)){
            return false;
        }
        
        //Verifica somente se o movimento da peça é valido, sem considerar os limetes do tabuleiro,  verificado pela classe Tabuleiro
        int diferencaLinha = linhaDestino - linhaOrigem;
        int diferencaColuna = colunaDestino - colunaOrigem;
        if (diferencaColuna == diferencaLinha || diferencaColuna == -diferencaLinha) {
            System.out.println("Movimento valido para Bispo: "+linhaOrigem+","+colunaOrigem+"->"+linhaDestino+","+colunaDestino);
            return true;
        }
        System.out.println("Movimento invalido para Bispo: "+linhaOrigem+","+colunaOrigem+"->"+linhaDestino+","+colunaDestino);
        return false;
    }
    //desenha o Bispo
    public void desenha(){
        if (cor == 1) {
            System.out.print("b");
        } else { 
            System.out.print("B");
        }
    }
    
}




