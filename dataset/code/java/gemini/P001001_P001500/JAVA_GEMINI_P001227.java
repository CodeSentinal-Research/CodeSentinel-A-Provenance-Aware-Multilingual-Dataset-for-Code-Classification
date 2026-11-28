import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            long MOD = 1000000007;
            if (n == 1) {
                System.out.println(0);
                sc.close();
                return;
            }
            if (n == 2) {
                System.out.println(1);
                sc.close();
                return;
            }
            long a = 0, b = 1;
            for (int i = 3; i <= n; i++) {
                long c = ((long)(i - 1) * (a + b)) % MOD;
                a = b;
                b = c;
            }
            System.out.println(b);
        }
        sc.close();
    }
}