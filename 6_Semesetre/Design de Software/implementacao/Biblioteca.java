import java.util.ArrayList;

public class Biblioteca {
	//Atributos
	ArrayList<Usuario> usuarios = new ArrayList<Usuario>();
	ArrayList<Obra> obras = new ArrayList<Obra>();
	ArrayList<Editora> editoras = new ArrayList<Editora>();
	ArrayList<Autor> autores = new ArrayList<Autor>();

	//Construtores
	
	//Get Set
	public ArrayList<Usuario> getUsuarios() {
		return this.usuarios;
	}
	public void setUsuarios(ArrayList<Usuario> novoUsuarios) {
		this.usuarios = novoUsuarios;
	}
	
	public ArrayList<Obra> getObras() {
		return this.obras;
	}
	public void setObras(ArrayList<Obra> novoObras) {
		this.obras = novoObras;
	}

	public ArrayList<Editora> getEditoras() {
		return this.editoras;
	}
	public void setEditoras(ArrayList<Editora> novoEditoras) {
		this.editoras = novoEditoras;
	}
		
	public ArrayList<Autor> getAutores() {
		return this.autores;
	}
	public void setAutores(ArrayList<Autor> novoAutores) {
		this.autores = novoAutores;
	}
	
	//Metodos
	public void addUsuario(Usuario u) {
		this.usuarios.add(u);
	}

	public void addObra(Obra o) {
		this.obras.add(o);
	}

	public void addEditora(Editora e) {
		this.editoras.add(e);
	}

	public void addAutor(Autor a) {
		this.autores.add(a);
	}

	public void removeUsuario(Usuario u) {
		this.usuarios.remove(u);
	}

	public void removeObra(Obra o) {
		this.obras.remove(o);
	}

	public void removeEditora(Editora e) {
		this.editoras.remove(e);
	}

	public void removeAutor(Autor a) {
		this.autores.remove(a);
	}

	public int cadastrarUsuario(String nome, String cpf, String telefone, String endereco) {
		Usuario u = new Usuario(nome, cpf, telefone, endereco);
		this.addUsuario(u);
		return 0;
	}

	public void pagarEmprestimo(String cpf, String dados) {
	}

	public Multa registrarDevolucao(String cpf, String dados, Data data) {
		Multa m = new Multa();
		return m;
	}

	public int registrarEmprestimo(String cpf, String dados, Data data) {
		return 0;
	}
}
