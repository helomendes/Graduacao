public class Exercicio1 {
	public static void main (String arrays[]) {
		Telefone vetor[] = new Telefone[5];
		for (int i = 0; i < 5; i++) {
			vetor[i] = new Telefone();
			vetor[i].setTelefone();
		}
		for (int j = 0; j < 5; j++)
			vetor[j].getTelefone();
	}
}
