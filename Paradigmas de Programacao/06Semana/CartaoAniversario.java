public class CartaoAniversario extends CartaoWeb{
    //Atributos
    
    //Construtores
    public CartaoAniversario(String destinatario) {
        this.setDestinatario(destinatario);
    }
    
    //Get Set
    public String getNomeCartao() {
        return "Aniversário";
    }
    
    //Metodos
    public String retornarMensagem(String remetente) {
        String mensagem;
        mensagem = "Querido(a) " + this.getDestinatario() + "\n";
        mensagem += "Feliz Aniversário!\n";
        mensagem += "Mais um ciclo se inicia!\n";
        mensagem += "Boa Sorte,\n";
        mensagem += remetente;
        return mensagem;
    }
}
