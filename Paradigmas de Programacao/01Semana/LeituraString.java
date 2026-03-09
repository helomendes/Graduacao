//Enunciado:
/*Escreva um programa em Java que leia uma
sentença digitada pelo usuário. Em seguida,
imprima o tamanho da sentença.*/

import java.util.Scanner;
public class LeituraString {
	public static void main(String args[]) {
		Scanner input = new Scanner (System.in);
		String texto;
		System.out.print("Digite uma sentenca: ");
		texto = input.nextLine();
		System.out.printf("O tamanho da sentenca \"%s\" eh %d\n", texto, texto.length());
	}
}
