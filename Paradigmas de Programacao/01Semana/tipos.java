import java.util.Scanner;
class Tipos {
	public static void main (String args[]) {
		Scanner input = new Scanner(System.in);
		
		System.out.println("Primeiro os números");
		int numI;
		long numL;
		double numD;
		float numF;
		boolean intB;
		boolean doubleB;
		System.out.print("Digite um inteiro: ");
		numI = input.nextInt();
		System.out.print("Digite um inteiro longo: ");
		numL = input.nextLong();
		System.out.print("Digite um double: ");
		numD = input.nextDouble();
//		System.out.print("Digite um float: ");
//		numF = input.nextFloat();
		System.out.println("Inteiro: " + numI);
		System.out.println("Long: " + numL);
		System.out.println("Double: " + numD);
//		System.out.println("Float: " + numF);
		
		System.out.println("\nAgora os caracteres");
		char carac;
		String simples;
		String complex;
//		System.out.print("Digite um caractere: ");
//		carac = input.next();
		System.out.print("Digite uma string simples: ");
		simples = input.next();
		System.out.print("Digite uma string complexa: ");
		complex = input.nextLine();
//		System.out.println("Caractere: " + carac);
		System.out.println("String Simples: " + simples);
		System.out.println("String Complexa: " + complex);
	}
}
