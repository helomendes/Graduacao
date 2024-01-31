public class Celular extends ProdutoEletronico {
    public Celular() {}
<<<<<<< HEAD
    public Celular(String marca) {
        super(null , 0, marca);
    }
    public Celular(int peso) {
        super(null, peso, null);
    }
    public Celular(String nomeFabricante, int peso, String marca) {
        super.setNomeFab(nomeFabricante);
        super.setPeso(peso);
        super.setMarca(marca);
=======

    public Celular(String marca) {
        this(null , 0, marca);
    }
    
    public Celular(float peso) {
        this(null, peso, null);
    }
    
    public Celular(String nomeFabricante, float peso, String marca) {
        super(nomeFabricante, peso, marca);
>>>>>>> eccd8c76678a4c510abc4b20ef4ffb80b380d0de
    }
    
    public void vender() {
        System.out.println("Venda de Celular.");
    }
    public void acionarGarantia() {
        System.out.println("Garantia de Celular Acionada.");
    }

<<<<<<< HEAD
    public void ligar() {
        this.ligado = true;
        System.out.println("Ligando Celular.");
    }

    public void desligar() {
        this.ligado = false;
        System.out.println("Desligando Celular.");
=======
    public void ligar_desligar() {
        if (this.getLigado()) {
            this.setLigado(false);
            System.out.println("Desligando Celular.");
        }
        else {
            this.setLigado(true);
            System.out.println("Ligando Celular.");
        }
>>>>>>> eccd8c76678a4c510abc4b20ef4ffb80b380d0de
    }
}
