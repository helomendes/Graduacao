public class FuncionarioMensalista extends Funcionario {
    protected float salario;

    public FuncionarioMensalista() {}

    public FuncionarioMensalista(float salario) {
        this("\0", 0, null, false, salario);
    }

    public FuncionarioMensalista(String nome, int matricula, Data contratacao, boolean estrangeiro, float salario) {
        super(nome, matricula, contratacao, estrangeiro);
        this.setSalario(salario);
    }

    public void setSalario(float salario) {
        if (salario >= 0)
            this.salario = salario;
    }
    public float getSalario() {
        return this.salario;
    }

    public String toString() {
        String str = super.toString();
        str += "$" + Float.toString(this.getSalario());
        return str;
    }

    public float calcularSalario() {
        return this.getSalario();
    }
    
    private final int teste() {
        return 666;
    }
}