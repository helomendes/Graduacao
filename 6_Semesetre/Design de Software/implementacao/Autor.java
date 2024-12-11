import java.util.ArrayList;

public class Autor extends Pessoa {
	ArrayList<Obra> obras = new ArrayList<Obra>();

	public Autor(String nome) {
		super(nome);
	}

	public ArrayList<Obra> getObras() {
		return this.obras;
	}

	public Autor(String nome, String cpf, String telefone, String endereco) {
		super(nome, cpf, telefone, endereco);
	}

	public void setObras(ArrayList<Obra> obras) {
		this.obras = obras;
	}

	public void addObra(Obra o) {
		this.obras.add(o);
	}

	public void removeObra(Obra o) {
		this.obras.remove(o);
	}
}
