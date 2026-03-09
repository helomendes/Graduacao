package Polimorfismo;
class ContaBancaria {
	private String nomeT;
	private double saldo;

	public ContaBancaria(String nomeT) {			//!
		this(nomeT, 0.0);
	}

	public ContaBancaria(double saldo) {			//!
		this("", saldo);
	}

	public ContaBancaria(String nomeT, double saldo) {
		this.setNomeT(nomeT);
		this.setSaldo(saldo);
	}

	public void setNomeT(String nomeT) {
		this.nomeT = nomeT;
	}
	public String getNomeT() {
		return this.nome;
	}

	public void setSaldo(double saldo) {
		this.saldo = saldo;
	}
	public double getSaldo() {
		return this.saldo;
	}
}

class Operacao {
	public ins soma(int x, int y) {			//!
		return x+y;
	}

	public double soma(double x, double y) {	//!
		return x+y;
	}

	public String soma(String x, String y) {	//!
		return x+y;
	}
}
