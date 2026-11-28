import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        System.out.println(minFlips(a, b, c));
    }

    public static int minFlips(int a, int b, int c) {
        int flips = 0;
        for (int i = 0; i < 32; i++) {
            boolean aBit = (a & (1 << i)) != 0;
            boolean bBit = (b & (1 << i)) != 0;
            boolean cBit = (c & (1 << i)) != 0;
            if ((aBit || bBit) != cBit) {
                if (cBit) {
                    flips++;
                } else {
                    if (aBit && bBit) {
                        flips += 2;
                   }
                    else {
                        flips += 1;
                    }
                }
            }
        }
        return flips;
    }
}
