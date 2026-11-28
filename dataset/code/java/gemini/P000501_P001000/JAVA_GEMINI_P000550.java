import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] p = new int[n], d = new int[n];
            for (int i = 0; i < n; i++) p[i] = scanner.nextInt();
            for (int i = 0; i < n; i++) d[i] = scanner.nextInt();
            long total = 0, curr = 0;
            int start = 0;
            for (int i = 0; i < n; i++) {
                int diff = p[i] - d[i];
                total += diff;
                curr += diff;
                if (curr < 0) {
                    start = i + 1;
                    curr = 0;
                }
            }
            System.out.println(total >= 0 ? start : -1);
        }
    }
}