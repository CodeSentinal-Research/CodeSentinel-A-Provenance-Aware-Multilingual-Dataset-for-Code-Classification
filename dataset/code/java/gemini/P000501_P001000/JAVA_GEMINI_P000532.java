import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] t = new int[n];
            for (int i = 0; i < n; i++) t[i] = scanner.nextInt();
            int k = scanner.nextInt();
            int time = 0;
            for (int i = 0; i < n; i++) {
                time += (i <= k) ? Math.min(t[i], t[k]) : Math.min(t[i], t[k] - 1);
            }
            System.out.println(time);
        }
    }
}