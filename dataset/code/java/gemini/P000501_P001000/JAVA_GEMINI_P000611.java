import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] vals = new int[n];
            for (int i = 0; i < n; i++) vals[i] = scanner.nextInt();
            int maxSum = 0;
            for (int i = 0; i < n / 2; i++) {
                maxSum = Math.max(maxSum, vals[i] + vals[n - 1 - i]);
            }
            System.out.println(maxSum);
        }
    }
}