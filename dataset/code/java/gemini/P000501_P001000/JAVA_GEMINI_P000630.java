import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] vals = new int[n];
            for (int i = 0; i < n; i++) vals[i] = scanner.nextInt();
            int k = scanner.nextInt();
            if (k >= 1 && k <= n) System.out.println(vals[n - k]);
            else System.out.println(-1);
        }
    }
}