public class Obra {
	String titulo;
	int anoPub;
	boolean disponivel;

	public Obra(String titulo, int anoPub, boolean disponivel) {
		this.setTitulo(titulo);
		this.setAnoPub(anoPub);
		this.setDisponivel(disponivel);
	}
	public Obra(String titulo) {
		this.setTitulo(titulo);
	}
	public Obra(int anoPub) {
		this.setAnoPub(anoPub);
	}
	public Obra(boolean disponivel) {
		this.setDisponivel(disponivel);
	}
	public Obra(String titulo, int anoPub) {
		this.setTitulo(titulo);
		this.setAnoPub(anoPub);
	}

	public String getTitulo() {
		return this.titulo;
	}
	public void setTitulo(String novoTitulo) {
		this.titulo = novoTitulo;
	}

	public int getAnoPub() {
		return this.anoPub;
	}
	public void setAnoPub(int novoAnoPub) {
		this.anoPub = novoAnoPub;
	}

	public boolean getDisponivel() {
		return this.disponivel;
	}
	public void setDisponivel(boolean novoDisponivel) {
		this.disponivel = novoDisponivel;
	}

}	
