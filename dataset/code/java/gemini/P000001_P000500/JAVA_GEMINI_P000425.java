import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] acc = new String[n];
            int[] m = new int[n];
            for (int i = 0; i < n; i++) { acc[i] = scanner.next(); m[i] = scanner.nextInt(); }
            int months = scanner.nextInt();
            for (int i = 0; i < n; i++) if (m[i] >= months) System.out.println(acc[i]);
        }
    }
}