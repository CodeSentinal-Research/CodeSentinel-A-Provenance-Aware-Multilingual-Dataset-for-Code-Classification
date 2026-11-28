import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        scanner.close();
        System.out.println(minSubArraySum(nums));
    }

    public static int minSubArraySum(int[] nums) {
        int n = nums.length;
        int minLength = n + 1;
        int sum = 0;
        int start = 0;
        int end = 0;
        boolean flag = false;

        for (end = 0; end < n; end++) {
            sum += nums[end];
            while (sum < 0) {
                sum -= nums[start];
                start++;
            }
            if (sum >= 0 && end - start + 1 < minLength) {
                minLength = end - start + 1;
                flag = true;
            }
        }
        if (!flag) {
            minLength = 0;
        }
        return minLength;
    }
}
