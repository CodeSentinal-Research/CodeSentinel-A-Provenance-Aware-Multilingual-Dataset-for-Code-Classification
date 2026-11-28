import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] events = new String[n], dates = new String[n];
            for (int i = 0; i < n; i++) { events[i] = scanner.next(); dates[i] = scanner.next(); }
            String date = scanner.next();
            for (int i = 0; i < n; i++) if (dates[i].equals(date)) System.out.println(events[i]);
        }
    }
}