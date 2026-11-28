import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            long MOD = 1000000007;
            if (n <= 2) {
                System.out.println(n);
                sc.close();
                return;
            }
            long a = 1, b = 2;
            for (int i = 3; i <= n; i++) {
                long c = (a + b) % MOD;
                a = b;
                b = c;
            }
            System.out.println(b);
        }
        sc.close();
    }
}