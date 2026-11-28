import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] ids = new String[n];
            String[] statuses = new String[n];
            for (int i = 0; i < n; i++) {
                ids[i] = scanner.next();
                statuses[i] = scanner.next();
            }
            String target = scanner.next();
            for (int i = 0; i < n; i++) {
                if (statuses[i].equals(target)) {
                    System.out.println(ids[i]);
                }
            }
        }
    }
}