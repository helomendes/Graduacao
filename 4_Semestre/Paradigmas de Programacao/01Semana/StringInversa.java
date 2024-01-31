//Enunciado:
/*Escreva um programa em Java que exiba uma String
na ordem inversa.*/

import java.util.Scanner;
public class StringInversa {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		String entrada;
		System.out.print("Insira uma string: ");
		entrada = input.nextLine();
		int tam = entrada.length();
		String saida = "";
		for (int i = tam-1; i >= 0; i--)
			System.out.print(entrada.charAt(i));
		System.out.print("\n");
	}
}
