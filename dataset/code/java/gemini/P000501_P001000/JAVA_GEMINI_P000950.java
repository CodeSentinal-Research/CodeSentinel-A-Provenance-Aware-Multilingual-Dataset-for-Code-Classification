import java.util.Scanner;

public class Solution {
    public static int[] phi1ToN(int n) {
        int[] phi = new int[n + 1];
        for (int i = 0; i <= n; i++) phi[i] = i;
        for (int i = 2; i <= n; i++) {
            if (phi[i] == i) {
                for (int j = i; j <= n; j += i) {
                    phi[j] -= phi[j] / i;
                }
            }
        }
        return phi;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[] res = phi1ToN(n);
            for (int i = 1; i <= n; i++) {
                System.out.print(res[i] + (i == n ? "" : " "));
            }
            System.out.println();
        }
        sc.close();
    }
}