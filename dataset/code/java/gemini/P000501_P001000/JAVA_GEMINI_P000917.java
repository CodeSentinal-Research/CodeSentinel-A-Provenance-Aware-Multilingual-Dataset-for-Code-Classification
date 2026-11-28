import java.util.Scanner;

public class Solution {
    public static long starsAndBars(int n, int k) {
        int total = n + k - 1;
        int r = k - 1;
        if (r < 0 || r > total) return 0;
        if (r > total - r) r = total - r;
        long ans = 1;
        for (int i = 1; i <= r; i++) {
            ans = ans * (total - i + 1) / i;
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            System.out.println(starsAndBars(n, k));
        }
        sc.close();
    }
}