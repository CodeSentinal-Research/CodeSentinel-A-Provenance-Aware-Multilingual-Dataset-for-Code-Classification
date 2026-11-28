import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            int k = scanner.nextInt();
            Map<Long, Integer> seen = new HashMap<>();
            seen.put(0L, -1);
            long cur = 0; int maxLen = 0;
            for (int i = 0; i < n; i++) {
                cur += nums[i];
                if (seen.containsKey(cur - k)) {
                    maxLen = Math.max(maxLen, i - seen.get(cur - k));
                }
                if (!seen.containsKey(cur)) seen.put(cur, i);
            }
            System.out.println(maxLen);
        }
    }
}