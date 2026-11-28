import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] vals = new int[n];
            for (int i = 0; i < n; i++) vals[i] = scanner.nextInt();
            int k = scanner.nextInt();
            boolean rev = true;
            for (int i = 0; i < n; i += k) {
                int len = Math.min(k, n - i);
                if (rev) {
                    int l = i, r = i + len - 1;
                    while (l < r) {
                        int tmp = vals[l]; vals[l] = vals[r]; vals[r] = tmp;
                        l++; r--;
                    }
                }
                rev = !rev;
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) sb.append(vals[i]).append(i == n - 1 ? "" : " ");
            System.out.println(sb.toString());
        }
    }
}