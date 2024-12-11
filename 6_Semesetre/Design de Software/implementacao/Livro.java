public class Livro extends Obra {
	Autor autor;
	Editora editora;

	public Livro(String titulo, int anoPub, boolean disponivel) {
		super(titulo, anoPub, disponivel);
	}
	public Livro(String titulo, int anoPub, boolean disponivel, Autor autor, Editora ed) {
		super(titulo, anoPub, disponivel);
		this.setAutor(autor);
		this.setEditora(ed);
	}
	public Livro(String titulo, int anoPub) {
		super(titulo, anoPub);
	}
	public Livro(String titulo, int anoPub, Autor autor, Editora ed) {
		super(titulo, anoPub);
		this.setAutor(autor);
		this.setEditora(ed);
	}
	public Livro(String titulo, int anoPub, Autor autor) {
		super(titulo, anoPub);
		this.setAutor(autor);
	}
	public Livro(String titulo, int anoPub, Editora ed) {
		super(titulo, anoPub);
		this.setEditora(ed);
	}


	public Autor getAutor() {
		return this.autor;
	}
	public void setAutor(Autor novoAutor) {
		this.autor = novoAutor;
	}

	public Editora getEditora() {
		return this.editora;
	}
	public void setEditora(Editora novoEditora) {
		this.editora = novoEditora;
	}

	public int pesquisar(String titulo, Autor autor) {
		return 0;
	}

}
