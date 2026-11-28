import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            long total = 0;
            for (int i = 0; i < n; i++) { nums[i] = scanner.nextInt(); total += nums[i]; }
            long leftSum = 0;
            int ans = -1;
            for (int i = 0; i < n; i++) {
                if (leftSum == total - leftSum - nums[i]) {
                    ans = i;
                    break;
                }
                leftSum += nums[i];
            }
            System.out.println(ans);
        }
    }
}