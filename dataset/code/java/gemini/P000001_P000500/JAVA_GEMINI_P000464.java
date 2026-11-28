import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int target = scanner.nextInt();
            int closest = 0, minDiff = Integer.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                int v = scanner.nextInt();
                int diff = Math.abs(v - target);
                if (diff < minDiff) {
                    minDiff = diff;
                    closest = v;
                }
            }
            System.out.println(closest);
        }
    }
}