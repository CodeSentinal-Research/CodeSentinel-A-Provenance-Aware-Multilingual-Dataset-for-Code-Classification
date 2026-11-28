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
        System.out.println(minSubArrayLen(nums, target));
    }

    public static int minSubArrayLen(int[] nums, int target) {
        int n = nums.length;
        if (n == 0) {
            return 0;
        }
        int left = 0, right = 0;
        int sum = nums[0];
        int minLength = n + 1;
        while (right < n) {
            if (sum < target) {
                sum += nums[++right];
            } else if (sum == target) {
                minLength = Math.min(minLength, right - left + 1);
                sum += nums[++right];
            } else {
                minLength = Math.min(minLength, right - left + 1);
                sum -= nums[left++];
            }
        }
        return minLength == n + 1 ? 0 : minLength;
    }
}
