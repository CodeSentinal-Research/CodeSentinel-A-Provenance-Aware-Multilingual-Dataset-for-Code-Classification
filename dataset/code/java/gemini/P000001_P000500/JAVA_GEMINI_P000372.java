import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            Map<String, String> records = new HashMap<>();
            for (int i = 0; i < n; i++) {
                String roll = scanner.next();
                String name = scanner.next();
                records.put(roll, name);
            }
            String targetRoll = scanner.next();
            if (records.containsKey(targetRoll)) {
                System.out.println(targetRoll + " " + records.get(targetRoll));
            } else {
                System.out.println("Record Not Found");
            }
        }
    }
}