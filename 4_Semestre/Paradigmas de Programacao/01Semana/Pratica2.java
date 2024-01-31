//Enunciado:
/*Crie um programa Java que leia uma sentença e remova
todos os espaços em branco*/

import java.util.Scanner;
public class Pratica2 {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		String entrada;
		System.out.print("Digite uma setenca: ");
		entrada = input.nextLine();

		int tam = entrada.length();
	        String saida = "";
		char c;
		for (int i = 0; i < tam; i++)
			if (entrada.charAt(i) != ' ')
				saida += entrada.charAt(i);
		System.out.println(saida);
	}
}
