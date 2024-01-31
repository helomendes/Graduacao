<<<<<<< HEAD
public class Televisao extends ProdutoEletronico {
    public Televisao() {}
    public Televisao(String marca) {
        super(null , 0, marca);
    }
    public Televisao(int peso) {
        super(null, peso, null);
    }
    public Televisao(String nomeFabricante, int peso, String marca) {
        super.setNomeFab(nomeFabricante);
        super.setPeso(peso);
        super.setMarca(marca);
=======
public class Televisao extends ProdutoEletronico implements Comparable<Televisao>{
    private float tamanho;
    
    public Televisao() {}

    public Televisao(String marca) {
        this(null , 0, marca, 0);
    }

    public Televisao(float tamanho) {
        this(null, 0, null, tamanho);
    }
    
    public Televisao(String nomeFabricante, float peso, String marca, float tamanho) {
        super(nomeFabricante, peso, marca);
        this.setTamanho(tamanho);
    }

    public void setTamanho(float tamanho) {
        if (tamanho >= 0)
            this.tamanho = tamanho;
    }
    public float getTamanho() {
        return this.tamanho;
>>>>>>> eccd8c76678a4c510abc4b20ef4ffb80b380d0de
    }
    
    public void vender() {
        System.out.println("Venda de Televisão.");
    }
<<<<<<< HEAD
=======

>>>>>>> eccd8c76678a4c510abc4b20ef4ffb80b380d0de
    public void acionarGarantia() {
        System.out.println("Garantia de Televisão Acionada.");
    }

<<<<<<< HEAD
    public void ligar() {
        this.ligado = true;
        System.out.println("Ligando Televisão.");
    }

    public void desligar() {
        this.ligado = false;
        System.out.println("Desligando Televisão.");
=======
    public void ligar_desligar() {
        if (this.getLigado()) {
            this.setLigado(false);
            System.out.println("Desligando Televisão.");
        }
        else {
            this.setLigado(true);
            System.out.println("Ligando Televisão.");
        }
    }

    public String toString() {
        String str = super.toString();
        str += tamanho;
        return str;
    }

    public int compareTo(Televisao t) {
        if (this.getPeso() > t.getPeso())
            return -1;
        else if (this.getPeso() < t.getPeso())
            return 1;
        return 0;
>>>>>>> eccd8c76678a4c510abc4b20ef4ffb80b380d0de
    }
}
