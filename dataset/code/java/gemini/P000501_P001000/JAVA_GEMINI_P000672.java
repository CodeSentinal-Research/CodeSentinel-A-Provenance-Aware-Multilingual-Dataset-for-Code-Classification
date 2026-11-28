import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] vals = new int[n];
            for (int i = 0; i < n; i++) vals[i] = scanner.nextInt();
            int N = scanner.nextInt();
            StringBuilder sb = new StringBuilder();
            boolean first = true;
            for (int i = 0; i < n; i++) {
                if ((i + 1) % N != 0) {
                    if (!first) sb.append(" ");
                    sb.append(vals[i]);
                    first = false;
                }
            }
            System.out.println(sb.toString());
        }
    }
}