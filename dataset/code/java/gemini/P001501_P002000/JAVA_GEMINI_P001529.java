import java.util.*;

public class Solution {
    private static long atMost(int[] nums, int k) {
        Map<Integer, Integer> count = new HashMap<>();
        int l = 0;
        long ans = 0;

        for (int r = 0; r < nums.length; r++) {
            count.put(nums[r], count.getOrDefault(nums[r], 0) + 1);
            while (count.size() > k) {
                count.put(nums[l], count.get(nums[l]) - 1);
                if (count.get(nums[l]) == 0) count.remove(nums[l]);
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), k = sc.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = sc.nextInt();
            System.out.println(atMost(nums, k) - atMost(nums, k - 1));
        }
        sc.close();
    }
}