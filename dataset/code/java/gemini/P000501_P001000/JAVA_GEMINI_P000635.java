import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] vals = new int[n];
            for (int i = 0; i < n; i++) vals[i] = scanner.nextInt();
            int g = scanner.nextInt();
            int[] groups = new int[g];
            for (int i = 0; i < g; i++) groups[i] = scanner.nextInt();
            int cur = 0;
            for (int sz : groups) {
                if (cur + sz <= n) {
                    int l = cur, r = cur + sz - 1;
                    while (l < r) {
                        int tmp = vals[l]; vals[l] = vals[r]; vals[r] = tmp;
                        l++; r--;
                    }
                    cur += sz;
                } else {
                    break;
                }
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) sb.append(vals[i]).append(i == n - 1 ? "" : " ");
            System.out.println(sb.toString());
        }
    }
}