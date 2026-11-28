import java.util.Scanner;

public class Solution {
    public static long nPr(int n, int r) {
        if (r < 0 || r > n) return 0;
        long ans = 1;
        for (int i = 0; i < r; i++) {
            ans *= (n - i);
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int r = sc.nextInt();
            System.out.println(nPr(n, r));
        }
        sc.close();
    }
}