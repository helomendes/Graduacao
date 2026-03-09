public class Data {
    private int dia;
    private int mes;
    private int ano;

    public Data() {}

    public Data(int dia, int mes, int ano) {
        this.setDia(dia);
        this.setMes(mes);
        this.setAno(ano);
    }

    public void setDia(int dia) {
        if (dia >= 0 && dia <= 30)
            this.dia = dia;
    }
    public int getDia() {
        return this.dia;
    }

    public void setMes(int mes) {
        if (mes >= 1 && mes <= 12)
            this.mes = mes;
    }
    public int getMes() {
        return this.mes;
    }

    public void setAno(int ano) {
        if (ano >= 0)
            this.ano = ano;
    }
    public int getAno() {
        return this.ano;
    }

    public String toString() {
        String str;
        str = Integer.toString(this.getDia()) + "_" + Integer.toString(this.getMes()) + "_" + Integer.toString(this.getAno());
        return str;
    }
}