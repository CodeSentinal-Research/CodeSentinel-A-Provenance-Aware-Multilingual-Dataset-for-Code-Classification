import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] vals = new int[n];
            for (int i = 0; i < n; i++) vals[i] = scanner.nextInt();
            int val = scanner.nextInt();
            StringBuilder sb = new StringBuilder();
            boolean first = true;
            for (int x : vals) {
                if (x != val) {
                    if (!first) sb.append(" ");
                    sb.append(x);
                    first = false;
                }
            }
            System.out.println(sb.toString());
        }
    }
}