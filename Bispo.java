public class Bispo {
    private final int cor;// poderia ser boolean mas prefiro trabalhar com INT e futuramente sera um
                   // atributo da classe peca
    private boolean estado; // 1 para peças ativas, 0 para peças inativas, será utilizado futuramente

    public Bispo(int _cor) {
        this.cor = _cor;
        this.estado = true;
    }

    public boolean checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
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
            System.out.println("b");
        } else { 
            System.out.println("B");
        }
    }
    
}




