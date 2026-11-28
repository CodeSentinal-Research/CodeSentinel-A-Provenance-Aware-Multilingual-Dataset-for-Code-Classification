import java.util.Scanner;

public class Solution {
    public static long calculateNCR(int n, int r) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n - r) r = n - r;
        long ans = 1;
        for (int i = 1; i <= r; i++) {
            ans = ans * (n - i + 1) / i;
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int r = sc.nextInt();
            System.out.println(calculateNCR(n, r));
        }
        sc.close();
    }
}