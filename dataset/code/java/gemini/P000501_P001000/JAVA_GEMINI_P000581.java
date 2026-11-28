import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] l1 = new int[n];
            for (int i = 0; i < n; i++) l1[i] = scanner.nextInt();
            int m = scanner.nextInt();
            int[] l2 = new int[m];
            for (int i = 0; i < m; i++) l2[i] = scanner.nextInt();
            int i = 0, j = 0;
            StringBuilder sb = new StringBuilder();
            boolean first = true;
            while (i < n && j < m) {
                if (!first) sb.append(" ");
                if (l1[i] <= l2[j]) sb.append(l1[i++]);
                else sb.append(l2[j++]);
                first = false;
            }
            while (i < n) {
                if (!first) sb.append(" ");
                sb.append(l1[i++]);
                first = false;
            }
            while (j < m) {
                if (!first) sb.append(" ");
                sb.append(l2[j++]);
                first = false;
            }
            System.out.println(sb.toString());
        }
    }
}