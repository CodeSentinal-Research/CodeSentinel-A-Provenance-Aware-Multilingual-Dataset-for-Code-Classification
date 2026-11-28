import java.util.*;

public class Main {
    private static int count = 0;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        int target = scanner.nextInt();
        findSubsequences(nums, target, 0, 0);
        System.out.println(count);
    }

    private static void findSubsequences(int[] nums, int target, int sum, int index) {
        if (index == nums.length) {
            if (sum == target) {
                count++;
            }
            return;
        }
        findSubsequences(nums, target, sum + nums[index], index + 1);
        findSubsequences(nums, target, sum, index + 1);
    }
}
