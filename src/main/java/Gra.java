import java.util.Scanner;

public class Gra {
    Plansza plansza;
    String info = "Ruch: {gora-dol}{prawo-lewo}\n   g - góra s - środek d - dół\n   l - lewo s - środek p - prawo";
    Gra() {
        plansza = new Plansza();
        start();
    }

    private int start() {
        Boolean czyX = false;
        for(int i = 0; i < 9; i += 1) {
            ruch(czyX);

            if(czyX) {
                czyX = false;
            }
            else {
                czyX = true;
            }

            if(plansza.check()) {
                System.out.println("Koniec gry!!");
                return 1;
            }
        }
        System.out.println("Koniec gry!!");
        return 0;
    }

    private void ruch(Boolean czyX) {
        plansza.show();
        System.out.println(info);
        Scanner scanner = new Scanner(System.in);
        if(czyX) {
            System.out.println("Ruch iksów: ");
        }
        else {
            System.out.println("Ruch kółek: ");
        }
        String linia = scanner.nextLine();
        plansza.change(linia, czyX);
    }
}
