import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] p = new String[n], bg = new String[n];
            for (int i = 0; i < n; i++) { p[i] = scanner.next(); bg[i] = scanner.next(); }
            String blood = scanner.next();
            for (int i = 0; i < n; i++) if (bg[i].equals(blood)) System.out.println(p[i]);
        }
    }
}