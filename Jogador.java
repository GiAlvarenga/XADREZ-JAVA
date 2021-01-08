public class Jogador{
    private final int cor;
    private final String nome;
    //falta inserir o vetor de peças

    public Jogador(String _nome , int _cor){
        this.cor = _cor;
        this.nome = _nome;
    }
    
    public void imprimir(){
        System.out.println(this.nome);
    }
}
