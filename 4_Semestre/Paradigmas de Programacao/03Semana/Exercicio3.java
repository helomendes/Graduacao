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
        this.dia = dia;
        this.mes = mes;
        this.ano = ano;
    }

    public void imprimirData() {
        System.out.printf("%d/%d/%d\n", this.dia, this.mes, this.ano);
    }
}

public class Exercicio3 {
    public static void main (String args[]) {
        Data meuAniversario = new Data();
        meuAniversario.ajustarData(13, 4, 2003);
        meuAniversario.imprimirData();
    }
}