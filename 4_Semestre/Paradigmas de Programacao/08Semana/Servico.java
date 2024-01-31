public class Servico implements Loja{
    //Atributos
<<<<<<< HEAD
    public char formato;
    public int duracao;
=======
    private char formato;
    private int duracao;
>>>>>>> eccd8c76678a4c510abc4b20ef4ffb80b380d0de

    //Construtores
    public Servico(){}
    public Servico(char formato) {
        this(formato, 0);
    }
    public Servico(int duracao) {
        this('\0', duracao);
    }
    public Servico(char formato, int duracao) {
        this.setFormato(formato);
        this.setDuracao(duracao);
    }

    //Get Set
    public void setFormato(char formato) {
        if (formato == 'R' || formato == 'L' || formato == 'D')
            this.formato = formato;
    }
    public char getFormato() {
        return this.formato;
    }

    public void setDuracao(int duracao) {
        if (duracao >= 0)
            this.duracao = duracao;
    }
    public int getDuracao() {
        return this.duracao;
    }

    //Metodos
<<<<<<< HEAD
    public void imprimirFormato() {
        if (this.getFormato() == 'R')
            System.out.println("Formato: Remoto");
        else if (this.getFormato() == 'L')
            System.out.println("Formato: em Loja");
        else if (this.getFormato() == 'D')
            System.out.println("Formato: em Domicílio");
    }

    public void imprimirServico() {
        this.imprimirFormato();
        System.out.println("Duração: " + this.getDuracao() + "min");
=======
    public String mostrarFormato() {
        if (this.getFormato() == 'R')
            return "Remoto";
        else if (this.getFormato() == 'L')
            return "EmLoja";
        else if (this.getFormato() == 'D')
            return "EmDomicílio";
        return null;
    }

    public String toString() {
        String str = this.mostrarFormato() + this.getDuracao() + "min";
        return str;
>>>>>>> eccd8c76678a4c510abc4b20ef4ffb80b380d0de
    }

    public void vender() {
        System.out.println("Venda de Serviço.");
    }
    public void acionarGarantia() {
        System.out.println("Garantia de Serviço Acionada.");
    }
}