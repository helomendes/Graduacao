import java.util.Scanner;
public class Telefone {
	//Atributos
	int DDI;
	int DDD;
	long numero;

	//Metodos
	
	public boolean valido(int DDI) {
		return DDI == 1 || DDI == 55 || DDI == 61;
	}

	public void getTelefone() {
		System.out.printf("+%d (%d) %d\n", this.DDI, this.DDD, this.numero);
	}

	public void setTelefone() {
		int DDI = 0;
    	        int DDD = 0;
		long numero = 0;
		Scanner input = new Scanner(System.in);
		System.out.println("Insira seu número de telefone (+00 00 000000000)");
		int resposta = 0;
		while (resposta != 1) {
			System.out.print("+");
			DDI = input.nextInt();
			DDD = input.nextInt();
			numero = input.nextLong();
			if (!valido(DDI))
				System.out.println("DDI inválido, tente novamente.");
			else
				resposta = 1;
		}
		this.DDI = DDI;
		this.DDD = DDD;
		this.numero = numero;
	}
}
