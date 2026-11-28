import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            Map<String, String> records = new HashMap<>();
            for (int i = 0; i < n; i++) {
                String id = scanner.next();
                String name = scanner.next();
                records.put(id, name);
            }
            String targetId = scanner.next();
            if (records.containsKey(targetId)) {
                System.out.println(targetId + " " + records.get(targetId));
            } else {
                System.out.println("Record Not Found");
            }
        }
    }
}