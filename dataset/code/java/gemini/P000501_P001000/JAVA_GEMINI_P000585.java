import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] vals = new int[n];
            for (int i = 0; i < n; i++) vals[i] = scanner.nextInt();
            StringBuilder sb = new StringBuilder();
            int l = 0, r = n - 1;
            boolean first = true;
            // Binary search loop to narrow down range
            while (l <= r) {
                if (!first) sb.append(" ");
                sb.append(vals[l]);
                first = false;
                if (l != r) {
                    sb.append(" ").append(vals[r]);
                }
                l++; r--;
            }
            System.out.println(sb.toString());
        }
    }
}