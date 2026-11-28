import java.util.Scanner;

public class Solution {
    public static long countDerangements(int n) {
        if (n == 0) return 1;
        if (n == 1) return 0;
        long prev2 = 1, prev1 = 0;
        for (int i = 2; i <= n; i++) {
            long curr = (i - 1) * (prev1 + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            System.out.println(countDerangements(n));
        }
        sc.close();
    }
}