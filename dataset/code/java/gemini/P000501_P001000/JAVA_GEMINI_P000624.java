import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            List<Integer> even = new ArrayList<>(), odd = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                int x = scanner.nextInt();
                if (x % 2 == 0) even.add(x);
                else odd.add(x);
            }
            StringBuilder sb = new StringBuilder();
            boolean first = true;
            for (int x : even) {
                if (!first) sb.append(" ");
                sb.append(x);
                first = false;
            }
            for (int x : odd) {
                if (!first) sb.append(" ");
                sb.append(x);
                first = false;
            }
            System.out.println(sb.toString());
        }
    }
}