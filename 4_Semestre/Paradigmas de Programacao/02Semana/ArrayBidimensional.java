//Enunciado:
/*Imprimir os elementos de um array bidimensional
inicializado com a instrução abaixo:
int[][] m = {{1,2}, {3,4}, {5, 6}};*/

public class ArrayBidimensional {
	public static void main (String args[]) {
		//instanciação
		int[][] m = new int[3][4];

		int[][] n = {{1,2},{3,4},{5,6}};

		for (int i = 0; i < n.length; i++) {
			for (int j = 0; j < n[i].length; j++)
				System.out.printf("%d\t", n[i][j]);
			System.out.println();
		}
	}
}
