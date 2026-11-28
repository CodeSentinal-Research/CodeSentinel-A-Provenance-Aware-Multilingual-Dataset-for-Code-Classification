import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] m = new String[n], g = new String[n];
            for (int i = 0; i < n; i++) { m[i] = scanner.next(); g[i] = scanner.next(); }
            String genre = scanner.next();
            for (int i = 0; i < n; i++) if (g[i].equals(genre)) System.out.println(m[i]);
        }
    }
}