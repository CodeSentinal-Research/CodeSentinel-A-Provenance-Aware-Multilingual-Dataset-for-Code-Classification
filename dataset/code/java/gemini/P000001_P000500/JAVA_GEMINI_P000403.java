import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] t = new String[n], s = new String[n];
            for (int i = 0; i < n; i++) { t[i] = scanner.next(); s[i] = scanner.next(); }
            String station = scanner.next();
            for (int i = 0; i < n; i++) if (s[i].equals(station)) System.out.println(t[i]);
        }
    }
}