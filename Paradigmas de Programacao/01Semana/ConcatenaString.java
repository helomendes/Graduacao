//Enunciado:
/*Escreva um programa em Java que leia duas palavras
digitadas pelo usuário, faça a concatenação e imprima a
palavra concatenada na tela.*/

import java.util.Scanner;
public class ConcatenaString {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		String a;
		String b;
		System.out.println("Digite duas palavras:");
		a = input.next();
		b = input.next();
		String c = a.concat(b);
		System.out.println(c);
	}
}
