import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), k = sc.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = sc.nextInt();

            Map<Integer, Integer> count = new HashMap<>();
            int l = 0;
            long ans = 0;

            for (int r = 0; r < n; r++) {
                count.put(nums[r], count.getOrDefault(nums[r], 0) + 1);
                while (count.size() > k) {
                    int left = nums[l++];
                    count.put(left, count.get(left) - 1);
                    if (count.get(left) == 0) count.remove(left);
                }
                ans += r - l + 1;
            }
            System.out.println(ans);
        }
        sc.close();
    }
}