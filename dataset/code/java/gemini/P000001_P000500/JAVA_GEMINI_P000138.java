import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int m = scanner.nextInt(), n = scanner.nextInt();
            long[] res = new long[m + n];
            for (int i = 0; i < m + n; i++) res[i] = scanner.nextLong();
            Arrays.sort(res);
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < m + n; i++) {
                if (i > 0) sb.append(' ');
                sb.append(res[i]);
            }
            System.out.println(sb.toString());
        }
    }
}