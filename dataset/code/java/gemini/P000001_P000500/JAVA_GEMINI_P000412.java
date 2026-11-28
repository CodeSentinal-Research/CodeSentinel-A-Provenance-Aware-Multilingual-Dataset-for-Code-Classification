import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] contacts = new String[n];
            for (int i = 0; i < n; i++) contacts[i] = scanner.next();
            String target = scanner.next();
            for (String c : contacts) if (c.equalsIgnoreCase(target)) System.out.println(c);
        }
    }
}