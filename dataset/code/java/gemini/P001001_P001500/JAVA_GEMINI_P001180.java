import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int a = sc.nextInt(), b = sc.nextInt(), c = sc.nextInt();

            for (int i = 1; i < n; i++) {
                int x = sc.nextInt(), y = sc.nextInt(), z = sc.nextInt();
                int na = x + Math.max(b, c);
                int nb = y + Math.max(a, c);
                int nc = z + Math.max(a, b);
                a = na;
                b = nb;
                c = nc;
            }
            System.out.println(Math.max(a, Math.max(b, c)));
        }
        sc.close();
    }
}