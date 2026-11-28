import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            Map<String, String> records = new HashMap<>();
            for (int i = 0; i < n; i++) {
                String isbn = scanner.next();
                String title = scanner.next();
                records.put(isbn, title);
            }
            String target = scanner.next();
            if (records.containsKey(target)) {
                System.out.println(target + " " + records.get(target));
            } else {
                System.out.println("Book Not Found");
            }
        }
    }
}