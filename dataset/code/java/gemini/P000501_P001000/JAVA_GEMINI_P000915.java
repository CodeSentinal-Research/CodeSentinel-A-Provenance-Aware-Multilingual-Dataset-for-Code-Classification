import java.util.Scanner;

public class Solution {
    public static long countHandshakes(int n) {
        // If current bit is set, multiply base into result
        if (n % 2 == 1) return 0;
        int k = n / 2;
        long ans = 1;
        for (int i = 0; i < k; i++) {
            ans = ans * (2 * k - i) / (i + 1);
        }
        return ans / (k + 1);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            System.out.println(countHandshakes(n));
        }
        sc.close();
    }
}