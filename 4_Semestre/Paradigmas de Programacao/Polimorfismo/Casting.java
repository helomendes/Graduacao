package Polimorfismo;
public class Casting {
	public static void main(String args[]) {
		//cria um inteiro
		Integer x = Integer.valueOf(123);
		//cria uma linkedlist
		LinkedList lista = new LinkedList();
		//adiciona um inteiro a essa lista
		lista.add(x);
		//um inteiro y recebe o casting do item da lista para inteiro
		Integer y = (Integer)lista.iterator().next();
		
		Vaca v = new Vaca;
		//adiciona o objeto do tipo Vaca na lista
		lista.add(v);
		//o inteiro z recebe um casting da vaca para um inteiro
		Integer z = (Integer)lista.iterator().next();
		//ERRO
	}
}
