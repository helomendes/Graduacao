public class Funcionario {
    protected String nome;
    protected int matricula;
    protected Data contratacao;
    protected boolean estrangeiro;

    public Funcionario() {}

    public Funcionario(String nome, int matricula, Data contratacao, boolean estrangeiro) {
        this.setNome(nome);
        this.setMatricula(matricula);
        this.setContratacao(contratacao);
        this.setEstrangeiro(estrangeiro);
    }

    public void setNome(String nome) {
        this.nome = nome;
    }
    public String getNome() {
        return this.nome;
    }

    public void setMatricula(int matricula) {
        if (matricula >= 0)
            this.matricula = matricula;
    }
    public int getMatricula() {
        return this.matricula;
    }

    public void setContratacao(Data cont) {
        if (cont == null)
            this.contratacao = new Data();
        else
            this.contratacao = cont;
    }
    public Data getContratacao() {
        if (this.contratacao == null)
            return new Data();
        return this.contratacao;
    }

    public void setEstrangeiro(boolean est) {
        this.estrangeiro = est;
    }
    public boolean getEstrangeiro() {
        return this.estrangeiro;
    }

    public String mostrarEstrangeiro() {
        if (this.getEstrangeiro())
            return "Estrangeiro";
        else
            return "Nacional";
    }

    public String toString() {
        String str;
        str = this.getNome() + Integer.toString(this.getMatricula()) + "_" + this.getContratacao().toString() + "_" + this.mostrarEstrangeiro();
        return str;
    }

    public float calcularSalario() {
        return 0.0f;
    }
}