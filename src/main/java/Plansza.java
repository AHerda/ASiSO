public class Plansza {
    private static final String PUSTE = " ";
    private static final String LINIA = "-----\n";


    private String plansza[][];
    Plansza() {
        create();
    }

    private void create() {
        plansza = new String[3][3];
        for(int i = 0; i < 3; i += 1) {
            for(int j = 0; j < 3; j += 1) {
                plansza[i][j] = " ";
            }
        }
    }

    private String stworzLinie(int linia) {
        return plansza[linia][0] + "|" + plansza[linia][1] + "|" + plansza[linia][2] + "\n";
    }

    public void show() {
        System.out.println(stworzLinie(0) + LINIA + stworzLinie(1) + LINIA + stworzLinie(2));
    }

    public void change(String dana, Boolean czyX) {
        if(dana.charAt(0) == 'g') {
            if(dana.charAt(1) == 'l') {
                if(czyX) {
                    plansza[0][0] = "X";
                }
                else {
                    plansza[0][0] = "O";
                }
            }
            else if(dana.charAt(1) == 's') {
                if(czyX) {
                    plansza[0][1] = "X";
                }
                else {
                    plansza[0][1] = "O";
                }
            }
            else if(dana.charAt(1) == 'p') {
                if(czyX) {
                    plansza[0][2] = "X";
                }
                else {
                    plansza[0][2] = "O";
                }
            }
        }
        if(dana.charAt(0) == 's') {
            if(dana.charAt(1) == 'l') {
                if(czyX) {
                    plansza[1][0] = "X";
                }
                else {
                    plansza[1][0] = "O";
                }
            }
            else if(dana.charAt(1) == 's') {
                if(czyX) {
                    plansza[1][1] = "X";
                }
                else {
                    plansza[1][1] = "O";
                }
            }
            else if(dana.charAt(1) == 'p') {
                if(czyX) {
                    plansza[1][2] = "X";
                }
                else {
                    plansza[1][2] = "O";
                }
            }
        }
        if(dana.charAt(0) == 'd') {
            if(dana.charAt(1) == 'l') {
                if(czyX) {
                    plansza[2][0] = "X";
                }
                else {
                    plansza[2][0] = "O";
                }
            }
            else if(dana.charAt(1) == 's') {
                if(czyX) {
                    plansza[2][1] = "X";
                }
                else {
                    plansza[2][1] = "O";
                }
            }
            else if(dana.charAt(1) == 'p') {
                if(czyX) {
                    plansza[2][2] = "X";
                }
                else {
                    plansza[2][2] = "O";
                }
            }
        }
    }

    public Boolean check() {
        if(plansza[0][0] == plansza[0][1] && plansza[0][0] == plansza[0][2]) {
            return true;
        }
        if(plansza[1][0] == plansza[1][1] && plansza[1][0] == plansza[1][2]) {
            return true;
        }
        if(plansza[2][0] == plansza[2][1] && plansza[2][0] == plansza[2][2]) {
            return true;
        }
        if(plansza[0][0] == plansza[1][0] && plansza[0][0] == plansza[2][0]) {
            return true;
        }
        if(plansza[0][1] == plansza[1][1] && plansza[0][1] == plansza[2][1]) {
            return true;
        }
        if(plansza[0][2] == plansza[1][2] && plansza[0][2] == plansza[2][2]) {
            return true;
        }
        if(plansza[0][0] == plansza[1][1] && plansza[0][0] == plansza[2][2]) {
            return true;
        }
        if(plansza[0][2] == plansza[1][1] && plansza[0][2] == plansza[2][0]) {
            return true;
        }
        return false;
    }
}
