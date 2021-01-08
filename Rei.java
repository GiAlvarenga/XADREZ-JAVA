public class Rei {
    private final int cor;// poderia ser boolean mas prefiro trabalhar com INT e futuramente sera um
                   // atributo da classepeca
    private boolean estado; // 1 para peças ativas, 0 para peças inativas, será utilizado futuramente

    public Rei(int _cor) {
        this.cor = _cor;
        this.estado = true;
    }

    public boolean checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
        //Verifica somente se o movimento da peça é valido, sem considerar os limetes do tabuleiro,  verificado pela classe Tabuleiro
        int diferencaLinha = linhaDestino - linhaOrigem;
        int diferencaColuna = colunaDestino - colunaOrigem;
        if (diferencaColuna >= -1 && diferencaColuna <= 1) {
            if (diferencaLinha >= -1 && diferencaLinha <= 1) {
                System.out.println("Movimento valido para Rei: "+linhaOrigem+","+colunaOrigem+"->"+linhaDestino+","+colunaDestino);
                return true;
            }
        }
        System.out.println("Movimento invalido para Rei: "+linhaOrigem+","+colunaOrigem+"->"+linhaDestino+","+colunaDestino);
        return false;
    }
    //desenha o rei
    public void desenha(){
        if (cor == 1) {
            System.out.println("r");
        } else { 
            System.out.println("R");
        }
    }
    
}




