public class Anotacoes {
	public static void main(String args[]) {
		String texto;
		
		//instaciação
		//texto = new String ("Seja bem vindo!");
		texto = "Seja bem vindo!";
		
		//tamanho
		int tam = texto.length();
		System.out.printf("O tamanho da sentença \"%s\" eh: %d\n", texto, tam);
		//igualdade
		String equal;
		equal = "Seja bem vindo!";
		String different;
		different = "Outra string.";
		
		boolean iguais = texto.equals(equal);
		boolean diferentes = texto.equals(different);
		if (iguais == true)
			System.out.printf("As strings \"%s\" e \"%s\" são iguais\n", texto, equal);
		else
			System.out.printf("As strings \"%s\" e \"%s\" são diferentes\n", texto, equal);
		if (diferentes == true)
			System.out.printf("As strings \"%s\" e \"%s\" são iguais\n", texto, different);
		else
			System.out.printf("As strings \"%s\" e \"%s\" são diferentes\n", texto, different);
		
		//compareTo(String s)
		//compara 2 strings em ordem alfabetica, 0 se forem iguais e != 0 se diferentes
		//compareToIgnoreCase(String s)
		//compara 2 strings em ordem alfabetica ignorando maiusculas e minusculas
		
		//concatena
		String a = "Bem vinda, ";
		String b = "Heloisa.";
		String c = a.concat(b);
		System.out.println(c);

		//indice
		int posicao = b.indexOf('i');
		System.out.printf("A letra 'i' está na posicao %d da string \"%s\"\n", posicao, b);
		String t1 = "ENCRUZILHADA";
		String t2 = "CRUZ";
		posicao = t1.indexOf(t2);
		System.out.printf("A string \"%s\" inicia na posicao %d da string \"%s\"\n", t2, posicao, t1);

		//replace(char caractere_antigo, char caractere_novo)
		//substring(int inicio, int fim)
		//charAt(int posicao)
		//toLowerCase()
		//toUpperCase()
	}
}
