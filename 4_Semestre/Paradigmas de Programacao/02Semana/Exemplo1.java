//Enunciado:
/*Crie um programa em Java que some os elementos
de um array formado por cinco elementos do tipo
inteiro.*/

import java.util.Scanner;

public class Exemplo1 {
	public static void main (String args[]) {
		Scanner input = new Scanner(System.in);

		int n;
		System.out.print("Qual o tamanho do vetor desejado? ");
		n = input.nextInt();

		int[] vetor = new int[n];
		int soma = 0;
		for (int i = 0; i < vetor.length; i++) {
			System.out.printf("Vetor[%d]: ", i+1);
			vetor[i] = input.nextInt();
			soma += vetor[i];
		}

		System.out.println();

		for (int j = 0; j < vetor.length; j++)
			System.out.printf("Vetor[%d] = %d\n", j+1, vetor[j]);
		System.out.println("\nSoma dos elementos = " + soma);
	}
}
