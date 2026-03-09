public class Classes {	
	public static void main(String args[]) {
		Funcionario obj1 = new Funcionario();
		Funcionario obj2 = new Funcionario();

		obj1.cadastrar("Heloisa", 2023, 700.00);
		obj2.cadastrar("Alguem", 2025, 5000);

		obj1.exibirDados();
		System.out.println();
		obj2.exibirDados();
		System.out.println();
		
		System.out.println(obj1.toString());
		System.out.println();
		System.out.println(obj2.toString());
		System.out.println();

		Funcionario[] empresa = new Funcionario[2];
		empresa[0] = new Funcionario();
		empresa[1] = new Funcionario();
		
		empresa[0].cadastrar("Tony Stark", 2012, 50000);
		empresa[1].cadastrar("Steve Rogers", 2012, 10000);

		for (int i = 0; i < 2; i++) {
			empresa[i].exibirDados();
			System.out.println();
		}
	}
}

