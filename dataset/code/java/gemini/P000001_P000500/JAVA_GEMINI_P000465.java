import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int diff = Math.abs(scanner.nextInt());
            Set<Integer> seen = new HashSet<>();
            boolean found = false;
            for (int i = 0; i < n; i++) {
                int v = scanner.nextInt();
                if (seen.contains(v - diff) || seen.contains(v + diff)) found = true;
                seen.add(v);
            }
            System.out.println(found ? "Yes" : "No");
        }
    }
}