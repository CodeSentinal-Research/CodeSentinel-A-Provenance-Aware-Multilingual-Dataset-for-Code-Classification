import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), k = sc.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = sc.nextInt();

            Map<Integer, Integer> count = new HashMap<>();
            for (int i = 0; i < k; i++) count.put(nums[i], count.getOrDefault(nums[i], 0) + 1);
            int ans = count.size() == k ? 1 : 0;

            for (int i = k; i < n; i++) {
                count.put(nums[i], count.getOrDefault(nums[i], 0) + 1);
                count.put(nums[i - k], count.get(nums[i - k]) - 1);
                if (count.get(nums[i - k]) == 0) count.remove(nums[i - k]);
                if (count.size() == k) ans++;
            }
            System.out.println(ans);
        }
        sc.close();
    }
}