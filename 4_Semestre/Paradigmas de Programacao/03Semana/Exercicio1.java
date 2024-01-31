class Pessoa {
    //Atributos
    private String nome;
    private int idade;
    private int dia;
    private int mes;
    private int ano;

    //Construtores
    public Pessoa() {}
    public Pessoa(String nome, int idade, int dia, int mes, int ano) {
        this.nome = nome;
        this.idade = idade;
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
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
    public void ajustarDataDeNascimento(int dia, int mes, int ano) {
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }

    public void calcularIdade(int diaAtual, int mesAtual, int anoAtual) {
        int idade;
        idade = anoAtual - this.ano - 1;

        if (mesAtual > this.mes)
            idade += 1;
        else if (mesAtual == this.mes)
            if (diaAtual >= this.dia)
            //feliz aniversario!
                idade += 1;
        this.setIdade(idade);
    }
}

public class Exercicio1 {
    public static void main (String args[]) {
        Pessoa[] vetor = new Pessoa[3];
        vetor[0] = new Pessoa("Grace Hopper", 0, 29, 12, 1906);
        vetor[1] = new Pessoa("Ada Lovelace", 0, 10, 12, 1815);
        vetor[2] = new Pessoa("Heloisa Mendes", 0, 13, 4, 2003);

        for (int i = 0; i < 3; i++) {
            vetor[i].calcularIdade(22, 8, 2023);
            System.out.printf("Nome: %s\nIdade: %d\n\n", vetor[i].getNome(), vetor[i].getIdade());
        }
    }
}