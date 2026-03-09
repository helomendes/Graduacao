package Polimorfismo.Quiz;

public class Main {
    public static void main(String args[]) {
        Animal a;
        Macaco m;
        Girafa g;
        m = new Macaco();
        a = m;
        //g = (Girafa)m;
        g = (Girafa)a;
    }
}