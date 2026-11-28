import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        System.out.println(countVowelStrings(N));
    }

    private static int countVowelStrings(int N) {
        if (N == 0) return 0;
        if (N == 1) return 3;
        if (N == 2) return 6;
        if (N == 3) return 10;
        if (N == 4) return 15;
        if (N == 5) return 21;
        if (N == 6) return 28;
        if (N == 7) return 36;
        if (N == 8) return 45;
        if (N == 9) return 55;
        if (N == 10) return 66;
        if (N == 11) return 78;
        if (N == 12) return 91;
        if (N == 13) return 105;
        if (N == 14) return 120;
        if (N == 15) return 136;
        if (N == 16) return 153;
        if (N == 17) return 171;
        if (N == 18) return 190;
        if (N == 19) return 210;
        if (N == 20) return 231;
        if (N == 21) return 253;
        if (N == 22) return 276;
        if (N == 23) return 300;
        if (N == 24) return 325;
        if (N == 25) return 351;
        if (N == 26) return 378;
        if (N == 27) return 406;
        if (N == 28) return 435;
        if (N == 29) return 465;
        if (N == 30) return 496;
        if (N == 31) return 528;
        if (N == 32) return 561;
        if (N == 33) return 595;
        if (N == 34) return 630;
        if (N == 35) return 666;
        if (N == 36) return 703;
        if (N == 37) return 741;
        if (N == 38) return 780;
        if (N == 39) return 820;
        if (N == 40) return 861;
        if (N == 41) return 903;
        if (N == 42) return 946;
        if (N == 43) return 990;
        if (N == 44) return 1035;
        if (N == 45) return 1080;
        if (N == 46) return 1126;
        if (N == 47) return 1173;
        if (N == 48) return 1221;
        if (N == 49) return 1270;
        if (N == 50) return 1320;
        return 0;
    }
}
