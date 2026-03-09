//Enunciado:
/*Faça um programa em Java que leia números inteiros
enquanto não for digitado o número -1, e calcule e
imprima a soma destes números*/

import java.util.Scanner;
class Segundo {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		System.out.println("Digite números inteiros (insira -1 para encerrar):");
		int soma = 0;
		int num = 0;
		num = input.nextInt();
		while(num > -1) {
			soma += num;
			num = input.nextInt();
		}
		System.out.println("Soma: " + soma);
		input.close();
	}
}
