public class Funcionario {
	//Atributos
	String nome;
	int anoContratacao;
	double salario;

	//Metodos
	public void exibirDados() {
		System.out.println("Nome: " + this.nome);
		System.out.println("Ano de Contratacao: " + this.anoContratacao);
		System.out.println("Salario: " + this.salario);
	}

	public void cadastrar(String nome, int ano, double salario) {
		this.nome = nome;
		this.anoContratacao = ano;
		this.salario = salario;
	}
}
