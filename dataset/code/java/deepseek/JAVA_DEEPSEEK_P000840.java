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
        int maxOperations = scanner.nextInt();
        System.out.println(minimumSize(nums, maxOperations));
    }

    private static long minimumSize(int[] nums, int maxOperations) {
        Arrays.sort(nums);
        int left = 1, right = (int)1e9;
        while (left < right) {
            int mid = (left + right) / 2;
            if (check(nums, mid, maxOperations)) {
                right = mid;
            } else {
                left = mid + 1;
            }
       }
        return right;
    }

    private static boolean check(int[] nums, int mid, int maxOperations) {
        for (int num : nums) {
            maxOperations -= (num + mid - 1) / mid - 1;
            if (maxOperations < 0) {
                return false;
            }
        }
        return true;
    }
}
