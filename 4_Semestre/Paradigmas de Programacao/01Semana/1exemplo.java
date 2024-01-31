//Enunciado:
/*Escreva um programa m Java para ler um
número inteiro digitado pelo usuário. Em seguida,
exiba o número na tela.*/

//import: compilador localizar uma classe
import java.util.Scanner;
class Exemplo1 {
	public static void main(String args[]) {
		//main é responsável por iniciar o programa Java

		//cria um objeto da classe Scanner
		Scanner input = new Scanner(System.in);
		//cria um objeto input para ler os dados fornecidos pelo usuário
		int num;
		System.out.println("Digite um número:");
		num = input.nextInt();
		//le o primeiro numero digitado pelo usuário e atribui a variável num
		System.out.println("Número digitado: " + num);
		input.close();
		//fecha o objeto input
	}
}
