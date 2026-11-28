import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] flights = new String[n];
            String[] dests = new String[n];
            for (int i = 0; i < n; i++) {
                flights[i] = scanner.next();
                dests[i] = scanner.next();
            }
            String target = scanner.next();
            for (int i = 0; i < n; i++) {
                if (dests[i].equals(target)) {
                    System.out.println(flights[i]);
                }
            }
        }
    }
}