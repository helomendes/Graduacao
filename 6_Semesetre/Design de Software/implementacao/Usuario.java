import java.util.ArrayList;

public class Usuario extends Pessoa {
	ArrayList<Emprestimo> emprestimos = new ArrayList<Emprestimo>();
	boolean atraso;

	public Usuario(String nome, String cpf, String telefone, String endereco) {
		super(nome, cpf, telefone, endereco);
	}

	public ArrayList<Emprestimo> getEmprestimo() {
		return this.emprestimos;
	}
	public void setEmprestimo(ArrayList<Emprestimo> novoEmprestimo) {
		this.emprestimos = novoEmprestimo;
	}

	public boolean getAtraso() {
		return this.atraso;
	}
	public void setAtraso(boolean novoAtraso) {
		this.atraso = novoAtraso;
	}

}
