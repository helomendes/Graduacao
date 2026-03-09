public class CartaoDiaDosNamorados extends CartaoWeb{
    //Atributos
    
    //Construtores
    public CartaoDiaDosNamorados(String destinatario) {
        this.setDestinatario(destinatario);
    }
    
    //Get Set
    public String getNomeCartao() {
        return "Dia dos Namorados";
    }
    
    //Metodos
    public String retornarMensagem(String remetente) {
        String mensagem;
        mensagem = "Querido(a) " + this.getDestinatario() + "\n";
        mensagem += "Feliz dia dos Namorados!\n";
        mensagem += "Espero que esse tenha sido o único cartão do dia dos namorados que tenha ganhado nessa data!\n";
        mensagem += "De todo meu coração,\n";
        mensagem += remetente;
        return mensagem;
    }
}
