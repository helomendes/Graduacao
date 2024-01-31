//Enunciado:
/*Crie um programa Java que leia uma sentença e substitua
todas as letras a por @*/

import java.util.Scanner;
public class Pratica1 {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		String entrada;
		System.out.print("Digite uma sentanca: ");
		entrada = input.nextLine();
		String saida = entrada.replace('a', '@');
		System.out.println(saida);
	}
}
