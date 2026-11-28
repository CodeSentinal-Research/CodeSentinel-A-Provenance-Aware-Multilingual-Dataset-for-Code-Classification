import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            String[] v = new String[n];
            int[] yr = new int[n];
            for (int i = 0; i < n; i++) { v[i] = scanner.next(); yr[i] = scanner.nextInt(); }
            int minYear = scanner.nextInt();
            for (int i = 0; i < n; i++) if (yr[i] > minYear) System.out.println(v[i]);
        }
    }
}