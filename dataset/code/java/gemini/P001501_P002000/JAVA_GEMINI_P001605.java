import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), k = sc.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = sc.nextInt();

            Map<Long, Integer> seen = new HashMap<>();
            seen.put(0L, -1);
            long curSum = 0;
            int maxLen = 0;

            for (int i = 0; i < n; i++) {
                curSum += nums[i];
                if (seen.containsKey(curSum - k)) {
                    maxLen = Math.max(maxLen, i - seen.get(curSum - k));
                }
                seen.putIfAbsent(curSum, i);
            }
            System.out.println(maxLen);
        }
        sc.close();
    }
}