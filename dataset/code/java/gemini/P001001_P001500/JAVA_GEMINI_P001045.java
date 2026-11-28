import java.util.Arrays;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = sc.nextInt();
            int m = sc.nextInt();
            int[] b = new int[m];
            for (int i = 0; i < m; i++) b[i] = sc.nextInt();
            System.out.println(Arrays.equals(a, b) ? "YES" : "NO");
        }
        sc.close();
    }
}