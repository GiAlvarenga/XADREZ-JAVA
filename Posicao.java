public class Posicao {
    private final int cor;
    private int linha; /*
                        * (sera tratado como int para facilitar a implementação, porem os movimentos
                        * das peças serão feitos por char (é simples transforamar de char para int,
                        * assim como foi feito no método que imprime o tabuleiro), neste caso é só
                        * subtrair 97 :)
                        */
    private int coluna;
    private boolean ocupado;

    public Posicao(int _linha, int _coluna, int _cor) {
        this.cor = _cor;
        this.linha = _linha;
        this.coluna = _coluna;
    }

    public int getCor() {
        return this.cor;
    }

    public boolean getOcupado() {
        return this.ocupado;
    }

    public boolean setOcupado() {
        this.ocupado = true;
    }

    public boolean setLivre() {
        this.ocupado = false;
    }
}
