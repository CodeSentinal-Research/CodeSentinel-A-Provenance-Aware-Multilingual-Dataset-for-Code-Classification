import java.util.*;
public class Solution {
    static boolean backtrack(int[] nums, int idx, int k, int target, int[] subsets) {
        if (idx == nums.length) return true;
        for (int i = 0; i < k; i++) {
            if (subsets[i] + nums[idx] <= target) {
                subsets[i] += nums[idx];
                if (backtrack(nums, idx + 1, k, target, subsets)) return true;
                subsets[i] -= nums[idx];
            }
            if (subsets[i] == 0) break;
        }
        return false;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            int total = 0;
            for (int i = 0; i < n; i++) { nums[i] = scanner.nextInt(); total += nums[i]; }
            int k = scanner.nextInt();
            if (total % k != 0 || n < k) { System.out.println("false"); return; }
            int target = total / k;
            Arrays.sort(nums);
            for (int i = 0; i < n / 2; i++) {
                int t = nums[i]; nums[i] = nums[n - 1 - i]; nums[n - 1 - i] = t;
            }
            if (nums[0] > target) { System.out.println("false"); return; }
            System.out.println(backtrack(nums, 0, k, target, new int[k]) ? "true" : "false");
        }
    }
}