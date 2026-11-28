import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = sc.nextInt();

            Map<Integer, Integer> count = new HashMap<>();
            count.put(0, 1);
            int curSum = 0;
            long ans = 0;

            for (int x : nums) {
                curSum += (x == 1 ? 1 : -1);
                ans += count.getOrDefault(curSum, 0);
                count.put(curSum, count.getOrDefault(curSum, 0) + 1);
            }
            System.out.println(ans);
        }
        sc.close();
    }
}