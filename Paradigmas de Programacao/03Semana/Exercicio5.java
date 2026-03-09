import java.util.Scanner;

class Estudante {
    //Atributos
    private String nome;
    private int notaFinal;

    //Get/Set
    private void setNome(String nome) {
        this.nome = nome;
    }
    public String getNome() {
        return this.nome;
    }

    private void setNotaFinal(int notaFinal) {
        this.notaFinal = notaFinal;
    }
    public int getNotaFinal() {
        return this.notaFinal;
    }

    //Metodo
    public String toString() {
        String linha;
        linha = this.nome;
        linha += this.notaFinal;
        return linha;
    }

    public void obterDados() {
        Scanner input = new Scanner (System.in);
        System.out.print("Nome: ");
        String nome = input.nextLine();
        this.setNome(nome);

        System.out.print("Nota Final: ");
        int nota = input.nextInt();
        this.setNotaFinal(nota); 

        input.nextLine();
    }

    public void mostrarDados() {
        System.out.printf("Nome: %s\n", this.getNome());
        System.out.printf("Nota Final: %d\n", this.getNotaFinal());
    }
}

public class Exercicio5 {
    public static void main (String args[]) {
        Estudante vetor[] = new Estudante[5];

        System.out.println("Insira os Dados dos Alunos:");
        for (int i = 0; i < vetor.length; i++) {
            vetor[i] = new Estudante();
            vetor[i].obterDados();
            System.out.println();
        }


        int soma = 0;
        int finais = 0;
        int reprovados = 0;
        int k = 0;
        
        Estudante aprovados[] = new Estudante[5];

        for (int j = 0; j < vetor.length; j++) {
            soma += vetor[j].getNotaFinal();

            if (vetor[j].getNotaFinal() < 40) {
                reprovados += 1;
            } else if (vetor[j].getNotaFinal() < 70) {
                finais += 1;
            } else {
                aprovados[k] = new Estudante();
                aprovados[k] = vetor[j];
                k++;
            }
        }

        float media = soma/vetor.length;
        System.out.println("##### RESULTADOS #####\n");
        System.out.printf("Média da turma: %f\n\n", media);
        System.out.printf("Exame final: %d\n\n", finais);
        System.out.printf("Reprovados: %d\n\n", reprovados);
        System.out.println("Aprovados:");

        for (int x = 0; x < aprovados.length; x++) {
            aprovados[x].mostrarDados();
            System.out.println();
        }
    }
}