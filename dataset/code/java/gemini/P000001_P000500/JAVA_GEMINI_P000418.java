import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] names = new String[n], dates = new String[n];
            for (int i = 0; i < n; i++) { names[i] = scanner.next(); dates[i] = scanner.next(); }
            String dateThresh = scanner.next();
            for (int i = 0; i < n; i++) if (dates[i].compareTo(dateThresh) < 0) System.out.println(names[i]);
        }
    }
}