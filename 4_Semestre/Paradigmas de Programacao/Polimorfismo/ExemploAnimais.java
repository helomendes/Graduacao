package Polimorfismo;
abstract class Animal {
	public Animal() {}

	public void emitirSom() {
		System.out.println("sem som");
	}
	public void cuidadosGerais() {
		System.out.println("cuidados importantes");
	}
}

class Abelha extends Animal {
	public Abelha() {}

	public void emitirSom() {
		System.out.println("bzzz");
	}

	public void voar() {
		System.out.println("abelha voando");
	}
}

class Gato extends Animal {
	public Gato() {}

	public void emitirSom() {
		System.out.println("miau");
	}

	public void caminhar() {
		System.out.println("gato caminhando");
	}
}

class Sapo extends Animal {
	public Sapo() {}

	public void emitirSom() {
		System.out.println("rebit");
	}

	public void pular() {
		System.out.println("sapo pulando");
	}
}

public class ExemploAnimais {
	public static void main(String args[]) {
		//COERCAO UPCAST
		
		Animal a1 = new Abelha();
		Animal a2 = new Gato();
		Animal a3 = new Sapo();
/*
		a1.emitirSom();
		a2.emitirSom();
		a3.emitirSom();

		a1.cuidadosGerais();
		a2.cuidadosGerais();
		a3.cuidadosGerais();
*/
		//COERCAO DOWNSCAST

		if (a1 instanceof Abelha){
			Abelha abelha = (Abelha)a1;
			abelha.emitirSom();
			abelha.voar();
		}
		if (a2 instanceof Gato) {
			Gato gato = (Gato)a2;
			gato.emitirSom();
			gato.caminhar();
		}
		if (a3 instanceof Sapo) {
			Sapo sapo = (Sapo)a3;
			sapo.emitirSom();
			sapo.pular();
		}
	}
}
