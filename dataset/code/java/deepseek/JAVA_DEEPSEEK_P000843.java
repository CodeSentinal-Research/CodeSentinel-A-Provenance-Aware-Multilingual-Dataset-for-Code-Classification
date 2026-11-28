import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        int p = scanner.nextInt();
        System.out.println(minimizeMaxDifference(nums, p));
    }

    private static int minimizeMaxDifference(int[] nums, int p) {
        Arrays.sort(nums);
        int n = nums.length;
        int left = 0, right = nums[n - 1] - nums[0];
        while (left < right) {
            int mid = (left + right) / 2;
            if (canFormPairs(nums, mid, p)) {
                right = mid;
            } else {
                left = mid + 1;
           }
        }
        return right;
    }

    private static boolean canFormPairs(int[] nums, int maxDiff, int p) {
        int count = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i + 1] - nums[i] <= maxDiff) {
                count++;
                i++;
            }
        }
        return count >= p;
    }
}
