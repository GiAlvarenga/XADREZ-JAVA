
public abstract class Peca {
    protected int cor;// poderia ser boolean mas prefiro trabalhar com INT e futuramente sera um
    // atributo da classepeca
    protected boolean estado; // 1 para peças ativas, 0 para peças inativas, será utilizado futuramente

    public abstract boolean checaMovimento(int linhaOrigem, int colunaOrigem, int linhaDestino, int colunaDestino, boolean haPeca);
}