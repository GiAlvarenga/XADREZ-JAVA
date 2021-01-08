public class Torre {
    private final int cor;// poderia ser boolean mas prefiro trabalhar com INT e futuramente sera um
                   // atributo da classepeca
    private boolean estado; // 1 para peças ativas, 0 para peças inativas, será utilizado futuramente

    public Torre(int _cor) {
        this.cor = _cor;
        this.estado = true;
    }

    public boolean checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
        //Verifica somente se o movimento da peça é valido, sem considerar os limetes do tabuleiro,  verificado pela classe Tabuleiros
        int diferencaLinha = linhaDestino - linhaOrigem;
        int diferencaColuna = colunaDestino - colunaOrigem;
        if (diferencaColuna == 0) {
            System.out.println("Movimento valido para Torre: "+linhaOrigem+","+colunaOrigem+"->"+linhaDestino+","+colunaDestino);
            return true;
        } else if (diferencaLinha == 0) {
            System.out.println("Movimento valido para Torre: "+linhaOrigem+","+colunaOrigem+"->"+linhaDestino+","+colunaDestino);
            return true;
        }
        System.out.println("Movimento invalido para Torre: "+linhaOrigem+","+colunaOrigem+"->"+linhaDestino+","+colunaDestino);
        return false;
    }
    //imprime a torra
    public void desenha(){
        if (cor == 1) {
            System.out.println("t");
        } else { 
            System.out.println("T");
        }
    }
    
}




