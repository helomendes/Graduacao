public class FuncionarioHorista extends Funcionario {
    public float valorHora;
    public int numeroHoras;

    public FuncionarioHorista() {}

    public FuncionarioHorista(float valorHora, int numeroHoras) {
        this("\0", 0, null, false, valorHora, numeroHoras);
    }

    public FuncionarioHorista(float valorHora) {
        this("\0", 0, null, false, valorHora, 0);
    }

    public FuncionarioHorista(int numeroHoras) {
        this("\0", 0, null, false, 0, numeroHoras);
    }

    public FuncionarioHorista(String nome, int matricula, Data contratacao, boolean estrangeiro, float valorHora, int numeroHoras) {
        super(nome, matricula, contratacao, estrangeiro);
        this.setValor(valorHora);
        this.setNumero(numeroHoras);
    }

    public void setValor(float valor) {
        if (valor >= 0)
            this.valorHora = valor;
    }
    public float getValor() {
        return this.valorHora;
    }

    public void setNumero(int numero) {
        if (numero >= 0)
            this.numeroHoras = numero;
    }
    public int getNumero() {
        return this.numeroHoras;
    }

    public String toString() {
        String str = super.toString();
        str += "$" + Float.toString(this.getValor()) + "*" + Integer.toString(this.getNumero());
        return str;
    }

    public float calcularSalario() {
        return this.getValor() * this.getNumero();
    }
}