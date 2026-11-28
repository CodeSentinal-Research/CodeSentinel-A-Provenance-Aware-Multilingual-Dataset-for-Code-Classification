import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        int k = scanner.nextInt();
        System.out.println(canPartitionKSubsets(nums, k));
    }

    public static boolean canPartitionKSubsets(int[] nums, int k) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % k != 0) {
            return false;
        }
        int target = sum / k;
        boolean[] used = new boolean[nums.length];
        return canPartition(nums, used, 0, k, 0, target);
    }

    private static boolean canPartition(int[] nums, boolean[] used, int start, int k, int sum, int target) {
        if (k == 0) {
            return true;
        }
        if (sum == target && k > 0) {
            return canPartition(nums, used, 0, k - 1, 0, target);
        }
        for (int i = start; i < nums.length; i++) {
            if (!used[i] && sum + nums[i] <= target) {
                used[i] = true;
                if (canPartition(nums, used, i + 1, k, sum + nums[i], target)) {
                    return true;
                }
                used[i] = false;
            }
        }
        return false;
    }
}
