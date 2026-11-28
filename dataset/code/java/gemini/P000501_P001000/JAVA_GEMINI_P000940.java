import java.util.Scanner;

public class Solution {
    public static String misereNim(int[] piles) {
        boolean allOnes = true;
        int xorSum = 0;
        for (int x : piles) {
            if (x > 1) allOnes = false;
            xorSum ^= x;
        }
        if (allOnes) {
            return (piles.length % 2 == 0) ? "First" : "Second";
        } else {
            return (xorSum != 0) ? "First" : "Second";
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int t = sc.nextInt();
            while (t-- > 0) {
                int n = sc.nextInt();
                int[] piles = new int[n];
                for (int i = 0; i < n; i++) piles[i] = sc.nextInt();
                System.out.println(misereNim(piles));
            }
        }
        sc.close();
    }
}