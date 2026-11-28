import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] emails = new String[n];
            Map<String, Integer> count = new HashMap<>();
            for (int i = 0; i < n; i++) {
                emails[i] = scanner.next();
                count.put(emails[i], count.getOrDefault(emails[i], 0) + 1);
            }
            Set<String> seen = new HashSet<>();
            for (String e : emails) {
                if (count.get(e) > 1 && !seen.contains(e)) {
                    System.out.println(e);
                    seen.add(e);
                }
            }
        }
    }
}