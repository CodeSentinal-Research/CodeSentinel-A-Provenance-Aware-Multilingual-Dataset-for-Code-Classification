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
        System.out.println(splitArray(nums, k));
    }

    public static int splitArray(int[] nums, int k) {
        int max = 0, sum = 0;
        for (int num : nums) {
            max = Math.max(max, num);
            sum += num;
        }
        if (k == 1) {
            return sum;
        }
        int l = max, r = sum;
        while (l < r) {
            int mid = (r - l) / 2 + l;
            if (canSplit(nums, k, mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

    private static boolean canSplit(int[] nums, int k, int target) {
        int count = 0, sum = 0;
        for (int num : nums) {
            if (sum + num > target) {
                count++;
                sum = 0;
            }
            sum += num;
        }
        if (sum > 0) {
            count++;
        }
        return count <= k;
    }
}
