public class Peao extends Peca{

    private boolean jaMoveu;

    public Peao(int _cor) {
        this.cor = _cor;
        this.estado = true;
        this.jaMoveu = false;
    }

    public boolean checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, boolean haPeca) {
        if ((linhaDestino == linhaOrigem) &&(colunaDestino == colunaOrigem)){
            return false;
        }
        
        //Verifica somente se o movimento da peça é valido, sem considerar os limetes do tabuleiro, que será verificado pela classe Tabuleiro
        int diferencaLinha = linhaDestino - linhaOrigem;
        int diferencaColuna = colunaDestino - colunaOrigem;
           //Caso a posição de destino esteja vazia
        if (haPeca == false) {
            //Caso o peao ja tenha se movido antes, não poderá mais executar o movimento de 2 casas
            if (jaMoveu) {
                if (this.cor == 1 && diferencaLinha == 1 && diferencaColuna == 0) {
                    System.out.println("Movimento valido para Peão: "+linhaOrigem+","+colunaOrigem+"->"+linhaDestino+","+colunaDestino);
                    return true;
                } else if (this.cor == 0 && diferencaLinha == -1 && diferencaColuna == 0) {
                    System.out.println("Movimento valido para Peão: "+linhaOrigem+","+colunaOrigem+"->"+linhaDestino+","+colunaDestino);
                    return true;
                }
            }
            //Caso o peão ainda não tenha se movido, poderá se mover 2 casas
            else {
                jaMoveu = true;
                if (this.cor == 1 && (diferencaLinha == 1 || diferencaLinha == 2) && diferencaColuna == 0) {
                    System.out.println("Movimento valido para Peão: "+linhaOrigem+","+colunaOrigem+"->"+linhaDestino+","+colunaDestino);
                    return true;
                }
                if (this.cor == 0 && (diferencaLinha == -1 || diferencaLinha == -2) && diferencaColuna == 0) {
                    System.out.println("Movimento valido para Peão: "+linhaOrigem+","+colunaOrigem+"->"+linhaDestino+","+colunaDestino);
                    return true;
                }
            }
            System.out.println("Movimento invalido para Peão: "+linhaOrigem+","+colunaOrigem+"->"+linhaDestino+","+colunaDestino);
            return false;
        }
        //Caso exista uma peça na posição de destino
        else {//se a peca estiver na frente do peao ele nao pode se mover
            if (colunaOrigem == colunaDestino) {
                System.out.println("Movimento invalido para Peão: "+linhaOrigem+","+colunaOrigem+"->"+linhaDestino+","+colunaDestino);
                return false;
            }
            //se a peca estiver na diagonal do peao, ele pode se mover
            if (diferencaColuna == 1 || diferencaColuna == -1) {
                if (this.cor == 1 && diferencaLinha == 1) {
                    jaMoveu = true;
                    System.out.println("Movimento valido para Peão: "+linhaOrigem+","+colunaOrigem+"->"+linhaDestino+","+colunaDestino);
                    return true;
                } else if (this.cor == 0 && diferencaLinha == -1) {
                    jaMoveu = true;
                    System.out.println("Movimento valido para Peão: "+linhaOrigem+","+colunaOrigem+"->"+linhaDestino+","+colunaDestino);
                    return true;
                }
            }
            System.out.println("Movimento invalido para Peão: "+linhaOrigem+","+colunaOrigem+"->"+linhaDestino+","+colunaDestino);
            return false;
        }
    }
    //Desenha o peao
    public void desenha(){
        if (cor == 1) {
            System.out.print("p");
        } else { 
            System.out.print("P");
        }
    }
    
}




