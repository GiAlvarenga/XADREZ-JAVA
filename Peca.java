
public abstract class Peca {
    private final int cor;
    private Square currentSquare;

    public Piece(int color, Square initSq) {
        this.color = color;
        this.currentSquare = initSq;
    }

    public boolean checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino) {
        if ((linhaDestino == linhaOrigem) &&(colunaDestino == colunaOrigem)){
            return false;
        }
        
}