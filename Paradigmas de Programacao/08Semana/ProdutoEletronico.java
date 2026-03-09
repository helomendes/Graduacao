public abstract class ProdutoEletronico implements Loja{
    //Atributos
<<<<<<< HEAD
    public String nomeFabricante;
    public int peso;
    public String marca;
    public boolean ligado;

    //Construtores
    public ProdutoEletronico() {}
    public ProdutoEletronico(String marca) {
        this(null , 0, marca);
    }
    public ProdutoEletronico(int peso) {
        this(null, peso, null);
    }
    public ProdutoEletronico(String nomeFabricante, int peso, String marca) {
=======
    protected String nomeFabricante;
    protected float peso;
    protected String marca;
    protected boolean ligado;

    //Construtores
    public ProdutoEletronico() {}

    public ProdutoEletronico(String marca) {
        this(null , 0, marca);
    }

    public ProdutoEletronico(float peso) {
        this(null, peso, null);
    }

    public ProdutoEletronico(String nomeFabricante, float peso, String marca) {
>>>>>>> eccd8c76678a4c510abc4b20ef4ffb80b380d0de
        this.setNomeFab(nomeFabricante);
        this.setPeso(peso);
        this.setMarca(marca);
    }
    
    //Get Set
    public void setNomeFab(String nomeFabricante) {
        this.nomeFabricante = nomeFabricante;
    }
    public String getNomeFab() {
        return this.nomeFabricante;
    }

<<<<<<< HEAD
    public void setPeso(int peso) {
        if (peso >= 0)
            this.peso = peso;
    }
    public int getPeso() {
=======
    public void setPeso(float peso) {
        if (peso >= 0)
            this.peso = peso;
    }
    public float getPeso() {
>>>>>>> eccd8c76678a4c510abc4b20ef4ffb80b380d0de
        return this.peso;
    }

    public void setMarca(String marca) {
        this.marca = marca;
    }
    public String getMarca() {
        return this.marca;
    }

<<<<<<< HEAD
    //Metodos
    public void imprimirProduto() {
        System.out.println("Nome Fabricante: " + this.getNomeFab());
        System.out.println("Peso: " + this.getPeso() + "kg");
        System.out.println("Marca: " + this.getMarca());
    }

    public void ligar(ProdutoEletronico p) {
        if (p instanceof Televisao) {
            Televisao t = (Televisao)p;
            t.ligar();
=======
    public void setLigado(boolean ligar) {
        this.ligado = ligar;
    }
    public boolean getLigado() {
        return this.ligado;
    }

    //Metodos
    public void ligar_desligar(ProdutoEletronico p) {
        if (p instanceof Televisao) {
            Televisao t = (Televisao)p;
            t.ligar_desligar();
>>>>>>> eccd8c76678a4c510abc4b20ef4ffb80b380d0de
        }
            
        else if (p instanceof Celular) {
            Celular c = (Celular)p;
<<<<<<< HEAD
            c.ligar();
=======
            c.ligar_desligar();
>>>>>>> eccd8c76678a4c510abc4b20ef4ffb80b380d0de
        }
            
    }

<<<<<<< HEAD
    //public void desligar();
=======
    public String mostrarLigado() {
        if (this.getLigado())
            return "Ligado";
        return "Desligado";
    }

    public String toString() {
        String str;
        str = this.getNomeFab() + this.getPeso() + this.getMarca();
        return str;
    }
>>>>>>> eccd8c76678a4c510abc4b20ef4ffb80b380d0de
}