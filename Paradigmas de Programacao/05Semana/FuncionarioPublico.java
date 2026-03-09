public class FuncionarioPublico extends FuncionarioMensalista {
    public int concurso;

    public FuncionarioPublico() {}

    public FuncionarioPublico(int concurso) {
        this("\0", 0, null, false, 0, concurso);
    }

    public FuncionarioPublico(String nome, int matricula, Data contratacao, boolean estrangeiro, float salario, int concurso) {
        super(nome, matricula, contratacao, estrangeiro, salario);
        this.setConcurso(concurso);
    }

    public void setConcurso(int concurso) {
        this.concurso = concurso;
    }
    public int getConcurso() {
        return this.concurso;
    }
}
