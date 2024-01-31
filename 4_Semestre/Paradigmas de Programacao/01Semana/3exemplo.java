//Enunciado:
/*Escreva um programa em Java que imprima a tabuada
de multiplicação de um número inteiro no intervalo
[1,10].*/

import java.util.Scanner;
class Exemplo3 {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int num;
		System.out.print("Digite um numero: ");
		num = input.nextInt();
		int mult;
		for(int i = 1; i <= 10; i++) {
			mult = num * i;
			System.out.println(num + " * " + i + " = " + mult);
		}
	}
}
