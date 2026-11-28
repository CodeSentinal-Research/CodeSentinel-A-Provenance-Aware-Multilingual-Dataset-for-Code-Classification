import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] piles = new int[n];
        for (int i = 0; i < n; i++) {
            piles[i] = scanner.nextInt();
        }
        System.out.println(nimSum(piles) == 0 ? "Second" : "First");
    }

    private static int nimSum(int[] piles) {
        int result = 0;
        for (int i = 0; i < piles.length; i++) {
            result ^= piles[i];
        }
        return result;
    }
}
