<<<<<<< HEAD
import java.util.ArrayList;

public class Aplicativo {
    public static void main(String args[]) {
        ProdutoEletronico t0 = new Televisao();
        Loja t1 = new Televisao("LG");
        Televisao t2 = new Televisao(6);
        Televisao t3 = new Televisao("Nacional", 5, "Samsung");
=======
import java.util.*;

public class Aplicativo {
    public static void main(String args[]) {
        /*ProdutoEletronico t0 = new Televisao();
        Loja t1 = new Televisao("LG");
        Televisao t2 = new Televisao(6);
        Televisao t3 = new Televisao("Nacional", 5, "Samsung", true, 50.4f);
>>>>>>> eccd8c76678a4c510abc4b20ef4ffb80b380d0de

        Celular c0 = new Celular();
        Celular c1 = new Celular("Motorola");
        Celular c2 = new Celular(1);
<<<<<<< HEAD
        Celular c3 = new Celular("Elon Musk", 1, "SpaceX");
=======
        Celular c3 = new Celular("Elon Musk", 1, "SpaceX", true);
>>>>>>> eccd8c76678a4c510abc4b20ef4ffb80b380d0de

        Loja s0 = new Servico();
        Servico s1 = new Servico('R');
        Servico s2 = new Servico(50);
        Servico s3 = new Servico('D', 120); 
        
        ArrayList<Loja> lojinha = new ArrayList<Loja>();
        lojinha.add(t0);
        lojinha.add(c0);
        lojinha.add(s0);
        lojinha.add(t1);
        lojinha.add(c1);
        lojinha.add(s1);
        lojinha.add(t2);
        lojinha.add(c2);
        lojinha.add(s2);
        lojinha.add(t3);
        lojinha.add(c3);
        lojinha.add(s3);

        for (Loja produto : lojinha) {
            produto.vender();
            produto.acionarGarantia();
            
            if (produto instanceof Servico) {
                Servico s = (Servico)produto;
                s.imprimirServico();
            }
            //ProdutoEletronico p;
            //produto.ligar();
            if (produto instanceof ProdutoEletronico){
                ProdutoEletronico p = (ProdutoEletronico)produto;
<<<<<<< HEAD
                p.ligar(p);
            }
            System.out.println();
        }

=======
                p.ligar_desligar(p);
            }
            System.out.println();
        }*/

        Televisao t0 = new Televisao("LG Eletronics", 30.8f, "LG", 75);
        Televisao t1 = new Televisao("Mondial", 4.5f, "Sony", 32);
        Televisao t2 = new Televisao("Britânia", 16, "Philco", 50);

        HashSet<ProdutoEletronico> colecao = new HashSet<ProdutoEletronico>();
        colecao.add(t0);
        colecao.add(t1);
        colecao.add(t2);

        Iterator<ProdutoEletronico> i = colecao.iterator();
        while(i.hasNext()) {
            System.out.println(i.next().toString());
        }

        System.out.println();

        TreeSet<ProdutoEletronico> conj = new TreeSet<ProdutoEletronico>();
        conj.add(t0);
        conj.add(t1);
        conj.add(t2);

        Iterator<ProdutoEletronico> j = conj.iterator();
        while(j.hasNext()) {
            Televisao t = (Televisao)j.next();
            System.out.println(t.toString());
        }
>>>>>>> eccd8c76678a4c510abc4b20ef4ffb80b380d0de
    }
}