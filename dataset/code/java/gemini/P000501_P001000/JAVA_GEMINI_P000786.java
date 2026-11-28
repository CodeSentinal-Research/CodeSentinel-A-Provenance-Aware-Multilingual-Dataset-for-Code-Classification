import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            long total = 0;
            for (int i = 0; i < n; i++) { nums[i] = scanner.nextInt(); total += nums[i]; }
            long left = 0;
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < n; i++) {
                long right = total - left - nums[i];
                sb.append(Math.abs(left - right)).append(i == n - 1 ? "" : " ");
                left += nums[i];
            }
            System.out.println(sb.toString());
        }
    }
}