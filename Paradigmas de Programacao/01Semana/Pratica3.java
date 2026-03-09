//Enunciado:
/*Fazer um programa em Java que leia um nome no formato
comum, por exemplo “José Silva”, e o imprima no formato
“Silva, J.”.*/

import java.util.Scanner;
public class Pratica3 {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		String entrada;
		System.out.print("Insira seu nome: ");
		entrada = input.nextLine();
		
		String ultimoNome = "";
		String iniciais = "";
		int tam = entrada.length();

		iniciais += entrada.charAt(0);
		for (int i = 1; i < tam; i++) {
			if (entrada.charAt(i-1) == ' ') {
				iniciais += entrada.charAt(i);
				ultimoNome = "";
				ultimoNome += entrada.charAt(i);
			} else {
				ultimoNome += entrada.charAt(i);
			}
		}

		String saida = ultimoNome;
		saida += ", ";
		int tamIn = iniciais.length();
		for (int j = 0; j < tamIn - 1; j++) {
			saida += iniciais.charAt(j);
			saida += ". ";
		}
		
		System.out.println(saida);
	}
}
