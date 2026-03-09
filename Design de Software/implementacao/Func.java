public class Func {
	public void initBib(Biblioteca bib) {
		Autor a1 = new Autor("José de Alencar");
		Autor a2 = new Autor("Machado de Assis");
		Autor a3 = new Autor("Clarice Lispector");
		Autor a4 = new Autor("Graciliano Ramos");

		Editora e1 = new Editora("Arqueiro");
		Editora e2 = new Editora("Seguinte");

		Livro o1 = new Livro("Iracema", 1865, a1, e1);
		Livro o2 = new Livro("Senhora", 1875, a1, e1);
		Livro o3 = new Livro("Dom Casmurro", 1899, a2, e2);
		Livro o4 = new Livro("Helena", 1876, a2, e2);
		Livro o5 = new Livro("Felicidade Clandestina", 1971, a3, e1);
		Livro o6 = new Livro("A Hora da Estrela", 1977, a3, e1);
		Livro o7 = new Livro("Vidas Secas", 1938, a4, e2);
		Livro o8 = new Livro("Memórias do Cárcere", 1953, a4, e2);

		a1.addObra(o1);
		a1.addObra(o2);
		a2.addObra(o3);
		a2.addObra(o4);
		a3.addObra(o5);
		a3.addObra(o6);
		a4.addObra(o7);
		a4.addObra(o8);

		bib.addAutor(a1);
		bib.addAutor(a2);
		bib.addAutor(a3);
		bib.addAutor(a4);

		bib.addObra(o1);
		bib.addObra(o2);
		bib.addObra(o3);
		bib.addObra(o4);
		bib.addObra(o5);
		bib.addObra(o6);
		bib.addObra(o7);
		bib.addObra(o8);
	}
}
