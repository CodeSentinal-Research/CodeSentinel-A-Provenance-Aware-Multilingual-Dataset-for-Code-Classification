import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            int k = scanner.nextInt();
            Map<Integer, Integer> seen = new HashMap<>();
            seen.put(0, -1);
            int cur = 0;
            boolean ans = false;
            for (int i = 0; i < n; i++) {
                cur = (cur + nums[i]) % k;
                if (seen.containsKey(cur)) {
                    if (i - seen.get(cur) >= 2) { ans = true; break; }
                } else {
                    seen.put(cur, i);
                }
            }
            System.out.println(ans ? "true" : "false");
        }
    }
}