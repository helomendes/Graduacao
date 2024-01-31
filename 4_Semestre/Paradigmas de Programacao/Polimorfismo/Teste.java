package Polimorfismo;
import java.util.*;

public class Teste {
	public static void main(String args[]) {
		ArrayList<Integer> lista = new ArrayList<Integer>();
		lista.add(3);
		lista.add(10);
		lista.add(24);

		Iterator<Integer> i = lista.iterator();
		while(i.hasNext()) {
			Integer x = i.next();
			System.out.println(x);
		}
	}
}
