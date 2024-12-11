public class Periodico extends Obra {
	int volume;
	int mes;

	public int getVolume() {
		return this.volume;
	}
	public void setVolume(int novoVolume) {
		this.volume = novoVolume;
	}

	public int getMes() {
		return this.mes;
	}
	public void setMes(int novoMes) {
		this.mes = novoMes;
	}

	public int pesquisar(String titulo, int anoPub) {
		return 0;
	}
}
