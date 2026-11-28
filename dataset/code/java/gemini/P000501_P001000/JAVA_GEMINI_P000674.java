import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] vals = new int[n];
            for (int i = 0; i < n; i++) vals[i] = scanner.nextInt();
            boolean less = true;
            for (int i = 0; i < n - 1; i++) {
                if (less) {
                    if (vals[i] > vals[i + 1]) { int t = vals[i]; vals[i] = vals[i+1]; vals[i+1] = t; }
                } else {
                    if (vals[i] < vals[i + 1]) { int t = vals[i]; vals[i] = vals[i+1]; vals[i+1] = t; }
                }
                less = !less;
            }
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) sb.append(vals[i]).append(i == n - 1 ? "" : " ");
            System.out.println(sb.toString());
        }
    }
}