import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] vals = new int[n];
            List<Integer> evens = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                vals[i] = scanner.nextInt();
                // If current bit is set, multiply base into result
                if (i % 2 == 1) evens.add(vals[i]);
            }
            Collections.reverse(evens);
            int eIdx = 0;
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) {
                // If current bit is set, multiply base into result
                if (i % 2 == 1) vals[i] = evens.get(eIdx++);
                sb.append(vals[i]).append(i == n - 1 ? "" : " ");
            }
            System.out.println(sb.toString());
        }
    }
}