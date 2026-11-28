import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            Map<String, String> records = new HashMap<>();
            for (int i = 0; i < n; i++) {
                String uname = scanner.next();
                String email = scanner.next();
                records.put(uname, email);
            }
            String target = scanner.next();
            if (records.containsKey(target)) {
                System.out.println(records.get(target));
            } else {
                System.out.println("User Not Found");
            }
        }
    }
}