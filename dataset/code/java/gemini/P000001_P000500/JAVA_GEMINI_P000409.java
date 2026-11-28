import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] users = new String[n];
            for (int i = 0; i < n; i++) users[i] = scanner.next();
            String prefix = scanner.next();
            for (String u : users) if (u.startsWith(prefix)) System.out.println(u);
        }
    }
}