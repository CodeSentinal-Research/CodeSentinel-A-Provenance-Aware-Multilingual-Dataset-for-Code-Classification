import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] names = new String[n];
            for (int i = 0; i < n; i++) names[i] = scanner.next();
            String prefix = scanner.next();
            for (String name : names) {
                if (name.startsWith(prefix)) {
                    System.out.println(name);
                }
            }
        }
    }
}