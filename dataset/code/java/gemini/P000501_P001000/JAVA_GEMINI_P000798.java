import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            Map<Integer, Integer> seen = new HashMap<>();
            seen.put(0, -1);
            int cur = 0, maxLen = 0;
            for (int i = 0; i < n; i++) {
                cur += (nums[i] == 1 ? 1 : -1);
                if (seen.containsKey(cur)) {
                    maxLen = Math.max(maxLen, i - seen.get(cur));
                } else {
                    seen.put(cur, i);
                }
            }
            System.out.println(maxLen);
        }
    }
}