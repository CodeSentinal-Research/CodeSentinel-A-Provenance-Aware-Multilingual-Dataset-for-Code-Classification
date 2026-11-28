import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            long total = 0;
            for (int i = 0; i < n; i++) { nums[i] = scanner.nextInt(); total += nums[i]; }
            int p = scanner.nextInt();
            int target = (int)(total % p);
            if (target == 0) { System.out.println(0); return; }
            Map<Integer, Integer> seen = new HashMap<>();
            seen.put(0, -1);
            int cur = 0, minLen = n;
            for (int i = 0; i < n; i++) {
                cur = (cur + nums[i]) % p;
                int needed = (cur - target + p) % p;
                if (seen.containsKey(needed)) {
                    minLen = Math.min(minLen, i - seen.get(needed));
                }
                seen.put(cur, i);
            }
            System.out.println(minLen < n ? minLen : -1);
        }
    }
}