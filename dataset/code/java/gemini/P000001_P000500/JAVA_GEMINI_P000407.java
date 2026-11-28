import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] s = new String[n], a = new String[n];
            for (int i = 0; i < n; i++) { s[i] = scanner.next(); a[i] = scanner.next(); }
            String artist = scanner.next();
            for (int i = 0; i < n; i++) if (a[i].equals(artist)) System.out.println(s[i]);
        }
    }
}