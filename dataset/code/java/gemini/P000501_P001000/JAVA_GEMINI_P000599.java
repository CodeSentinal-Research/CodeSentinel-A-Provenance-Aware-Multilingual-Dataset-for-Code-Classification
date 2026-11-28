import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] vals = new int[n];
            Map<Integer, Integer> counts = new HashMap<>();
            for (int i = 0; i < n; i++) {
                vals[i] = scanner.nextInt();
                counts.put(vals[i], counts.getOrDefault(vals[i], 0) + 1);
            }
            StringBuilder sb = new StringBuilder();
            boolean first = true;
            for (int x : vals) {
                if (counts.get(x) == 1) {
                    if (!first) sb.append(" ");
                    sb.append(x);
                    first = false;
                }
            }
            System.out.println(sb.toString());
        }
    }
}