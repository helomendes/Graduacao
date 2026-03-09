//Enunciado:
/*Escreva um programa em Java que leia dois números
digitados pelo usuário. Em seguida, imprima os
números em ordem crescente.*/

import java.util.Scanner;
class Exemplo2 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int a;
		int b;
		System.out.print("Digite um numero: ");
		a = input.nextInt();
		System.out.print("Digite outro numero: ");
		b = input.nextInt();
		if (a < b) {
			System.out.println(a + " " + b);
		} else {
			System.out.println(b + " " + a);
		}
		input.close();
	}
}
