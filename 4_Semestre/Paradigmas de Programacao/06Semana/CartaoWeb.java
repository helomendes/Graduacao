public abstract class CartaoWeb {
    //Atributos
    String destinatario;

    //Construtores
    
    //Get Set
    public abstract String getNomeCartao();

    public void setDestinatario(String destinatario) {
        this.destinatario = destinatario;
    }
    public String getDestinatario() {
        return this.destinatario;
    }

    //Metodos
    public abstract String retornarMensagem(String remetente);
}
