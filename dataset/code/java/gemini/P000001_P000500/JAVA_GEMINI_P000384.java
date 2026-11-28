import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            Map<String, String> records = new HashMap<>();
            for (int i = 0; i < n; i++) {
                String inv = scanner.next();
                String details = scanner.next();
                records.put(inv, details);
            }
            String target = scanner.next();
            if (records.containsKey(target)) {
                System.out.println(target + " " + records.get(target));
            } else {
                System.out.println("Invoice Not Found");
            }
        }
    }
}