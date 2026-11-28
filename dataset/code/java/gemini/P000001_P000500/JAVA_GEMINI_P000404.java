import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] d = new String[n], s = new String[n];
            for (int i = 0; i < n; i++) { d[i] = scanner.next(); s[i] = scanner.next(); }
            String spec = scanner.next();
            for (int i = 0; i < n; i++) if (s[i].equals(spec)) System.out.println(d[i]);
        }
    }
}