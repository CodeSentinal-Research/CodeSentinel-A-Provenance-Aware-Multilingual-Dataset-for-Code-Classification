import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] piles = new int[n];
        for (int i = 0; i < n; i++) {
            piles[i] = scanner.nextInt();
        }
        System.out.println(nim(piles) == 0 ? "First" : "Second");
    }

    private static int nim(int[] piles) {
        int res = 0;
        for (int i = 0; i < piles.length; i++) {
            res ^= piles[i];
        }
        return res;
    }
}
