import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            int goal = scanner.nextInt();
            Map<Integer, Integer> counts = new HashMap<>();
            counts.put(0, 1);
            int cur = 0; long ans = 0;
            for (int x : nums) {
                cur += x;
                ans += counts.getOrDefault(cur - goal, 0);
                counts.put(cur, counts.getOrDefault(cur, 0) + 1);
            }
            System.out.println(ans);
        }
    }
}