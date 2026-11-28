import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int target = scanner.nextInt();
        int[] nums = new int[N];
        for (int i = 0; i < N; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println(countWays(nums, target, 0, 0, 0));
    }

    private static int countWays(int[] nums, int target, int index, int sum, int sign) {
        if (index == nums.length) {
            if (sum == target && sign == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            int add = sum + nums[index] * (sign == 1 ? 1 : -1);
            int subtract = countWays(nums, target, index + 1, add, sign * (nums[index] == 0 ? 1 : -1));
            int keep = countWays(nums, target, index + 1, sum, sign);
            return add == target ? subtract + keep : keep;
        }
    }
}
