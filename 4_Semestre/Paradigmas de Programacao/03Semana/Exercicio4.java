class Data {
    //Atributos
    private int dia;
    private int mes;
    private int ano;

    //Get/Set
    private void setDia(int dia) {
        this.dia = dia;
    }
    public int getDia() {
        return this.dia;
    }

    private void setMes(int mes) {
        this.mes = mes;
    }
    public int getMes() {
        return this.mes;
    }

    private void setAno(int ano) {
        this.ano = ano;
    }
    public int getAno() {
        return this.ano;
    }

    //Metodos
    public void ajustarData(int dia, int mes, int ano) {
        this.setDia(dia);
        this.setMes(mes);
        this.setAno(ano);
    }

    public void imprimirData() {
        System.out.printf("%d/%d/%d\n", this.dia, this.mes, this.ano);
    }
}

class Pessoa {
    //Atributos
    private String nome;
    private int idade;
    private Data data;

    //Construtores
    public Pessoa() {}

    public Pessoa(String nome, int dia, int mes, int ano) {
        this.nome = nome;
        Data date = new Data();
        date.ajustarData(dia, mes, ano);
        this.setData(date);
        this.calcularIdade(22, 8, 2023);
    }

    //Get/Set
    private void setNome(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return this.nome;
    }

    private void setIdade(int idade) {
        this.idade = idade;
    }
    public int getIdade() {
        return this.idade;
    }

    private void setData(Data data) {
        this.data = data;
    }
    public Data getData() {
        return this.data;
    }

    //Metodos
    public void calcularIdade(int diaAtual, int mesAtual, int anoAtual) {
        int idade;
        idade = anoAtual - this.data.getAno() - 1;

        if (mesAtual > this.data.getMes())
            idade += 1;
        else if (mesAtual == this.data.getMes())
            if (diaAtual >= this.data.getDia())
            //feliz aniversario!
                idade += 1;
        this.setIdade(idade);
    }
}

public class Exercicio4 {
    public static void main (String args[]) {
        Pessoa[] vetor = new Pessoa[3];
        vetor[0] = new Pessoa("Grace Hopper", 29, 12, 1906);
        vetor[1] = new Pessoa("Ada Lovelace", 10, 12, 1815);
        vetor[2] = new Pessoa("Heloisa Mendes", 13, 4, 2003);

        for (int i = 0; i < 3; i++) {
            System.out.printf("Nome: %s\nIdade: %d\nData de Nascimento: ", vetor[i].getNome(), vetor[i].getIdade());
            vetor[i].getData().imprimirData();
            System.out.println();
        }
    }
}