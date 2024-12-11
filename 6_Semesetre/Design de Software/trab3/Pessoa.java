public class Pessoa {
	//Atributos
	String nome;
	String cpf;
	String telefone;
	String endereco;

	//Construtores
	public Pessoa(String nome, String cpf, String telefone, String endereco) {
		this.setNome(nome);
		this.setCpf(cpf);
		this.setTelefone(telefone);
		this.setEndereco(endereco);
	}	
	public Pessoa(String nome) {
		this.setNome(nome);
	}
	
	//Get Set
	public String getNome() {
		return this.nome;
	}
	public void setNome(String novoNome) {
		this.nome = novoNome;
	}

	public String getCpf() {
		return this.cpf;
	}
	public void setCpf(String novoCpf) {
		this.cpf = novoCpf;
	}

	public String getTelefone() {
		return this.telefone;
	}
	public void setTelefone(String novoTelefone) {
		this.telefone = novoTelefone;
	}

	public String getEndereco() {
		return this.endereco;
	}
	public void setEndereco(String novoEndereco) {
		this.endereco = novoEndereco;
	}

	//Metodos
}
