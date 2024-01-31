//Enunciado:
/*Faça um programa em Java que calcule e imprima a
soma dos 10 primeiros múltiplos de 3.*/

class Terceiro {
	public static void main(String args[]) {
		int soma = 0;
		int num = 1;
		int i = 0;
		while (i < 10) {
			if (num % 3 == 0) {
				soma += num;
				i++;
			}
			num++;
		}
		System.out.println("Soma dos 10 primeiros múltiplos de 3: " + soma);
	}
}
