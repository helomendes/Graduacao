//Enunciado:
/*Construa um programa em Java que leia um número
inteiro e diga se ele é par ou ímpar.*/

import java.util.Scanner;
class Primeiro {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int num;
		System.out.print("Digite um número inteiro: ");
		num = input.nextInt();
		if (num % 2 == 0)
			System.out.println("Par");
		else
			System.out.println("Impar");
	}
}
