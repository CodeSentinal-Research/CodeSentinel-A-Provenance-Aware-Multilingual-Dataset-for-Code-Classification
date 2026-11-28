import java.util.Scanner;

public class Solution {
    public static String nimWinner(int[] piles) {
        int xorSum = 0;
        for (int x : piles) {
            xorSum ^= x;
        }
        return (xorSum != 0) ? "First" : "Second";
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int t = sc.nextInt();
            while (t-- > 0) {
                int n = sc.nextInt();
                int[] piles = new int[n];
                for (int i = 0; i < n; i++) piles[i] = sc.nextInt();
                System.out.println(nimWinner(piles));
            }
        }
        sc.close();
    }
}