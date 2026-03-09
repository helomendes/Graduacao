import java.util.Random;

abstract class Animal {
	public Animal() {}
	public abstract void emitirSom();
}

class Cachorro extends Animal {
	public Cachorro() {}
	public void emitirSom() {
		System.out.println("Au Au!!!");
	}
}

class Gato extends Animal {
	public Gato() {}
	public void emitirSom() {
		System.out.println("Miau!");
	}
}

class Pato extends Animal {
	public Pato() {}
	public void emitirSom() {
		System.out.println("Quack!");
	}
}

public class Inclusao {
	public static void main(String args[]) {
		/*Animal x, y, z;

		x = new Cachorro();
		x.emitirSom();

		y = new Gato();
		y.emitirSom();

		z = new Pato();
		z.emitirSom();*/

		Animal[] gaiolao = new Animal[3];
		gaiolao[0] = new Cachorro();
		gaiolao[1] = new Gato();
		gaiolao[2] = new Pato();

		Random aleatorio = new Random();

		Animal animalEscolhido;

		for (int i = 0; i < 5; i++) {
			animalEscolhido = gaiolao[aleatorio.nextInt(3)];
			animalEscolhido.emitirSom();
		}
	}
}
