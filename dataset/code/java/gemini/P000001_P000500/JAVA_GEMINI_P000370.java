import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            Set<Integer> seen = new HashSet<>();
            int dup = -1;
            for (int i = 0; i < n; i++) {
                int v = scanner.nextInt();
                if (seen.contains(v) && dup == -1) {
                    dup = v;
                }
                seen.add(v);
            }
            System.out.println(dup);
        }
    }
}