public class Emprestimo {
	Data inicio;
	Data fim;
	int atraso;
	boolean encerrado;
	Obra obra;

	public Data getInicio() {
		return this.inicio;
	}
	public void setInicio(Data inicio) {
		this.inicio = inicio;
	}
	
	public Data getFim() {
		return this.fim;
	}
	public void setFim(Data fim) {
		this.fim = fim;
	}
	
	public int getAtraso() {
		return this.atraso;
	}
	public void setAtraso(int atraso) {
		this.atraso = atraso;
	}
	
	public boolean getEncerrado() {
		return this.encerrado;
	}
	public void setEncerrado(boolean encerrado) {
		this.encerrado = encerrado;
	}
	
	public Obra getObra() {
		return this.obra;
	}
	public void setObra(Obra obra) {
		this.obra = obra;
	}
	
	public Multa calcularValor() {
		Multa m = new Multa();
		return m;
	}

	public void pagarEmprestimo() {
	}

	public Multa registrarDevolucao(Data data) {
		Multa m = new Multa();
		return m;
	}
}
