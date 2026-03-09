public class CartaoNatal extends CartaoWeb{
    //Atributos
    
    //Construtores
    public CartaoNatal(String destinatario) {
        this.setDestinatario(destinatario);
    }
    
    //Get Set
    public String getNomeCartao() {
        return "Natal";
    }
    
    //Metodos
    public String retornarMensagem(String remetente) {
        String mensagem;
        mensagem = "Querido(a) " + this.getDestinatario() + "\n";
        mensagem += "Feliz Natal!\n";
        mensagem += "Espero que o Papai Noel tenha sido generoso!\n";
        mensagem += "Boas Festas,\n";
        mensagem += remetente;
        return mensagem;
    }
}