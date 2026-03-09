//Enunciado:
/*Escreva um programa em Java que leia duas palavras
digitadas pelo usuário e verifique se elas são iguais.*/

import java.util.Scanner;
public class IgualdadeString {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		String t1, t2;
		System.out.println("Insira duas palavras:");
		t1 = input.next();
		t2 = input.next();
		if (t1.equals(t2))
			System.out.println("São iguais");
		else
			System.out.println("São diferentes");
	}
}
