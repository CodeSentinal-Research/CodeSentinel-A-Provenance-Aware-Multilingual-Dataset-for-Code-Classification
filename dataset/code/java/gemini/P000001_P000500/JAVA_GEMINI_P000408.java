import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] emails = new String[n];
            for (int i = 0; i < n; i++) emails[i] = scanner.next();
            String domain = scanner.next();
            if (!domain.startsWith("@")) domain = "@" + domain;
            for (String e : emails) if (e.endsWith(domain)) System.out.println(e);
        }
    }
}