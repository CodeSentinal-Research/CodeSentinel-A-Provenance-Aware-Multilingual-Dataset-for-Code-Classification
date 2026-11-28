import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int Goal = scanner.nextInt();
        int[] nums = new int[N];
        for (int i = 0; i < N; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println(countSubarrays(nums, Goal));
    }

    private static long countSubarrays(int[] nums, int goal) {
        long count = 0;
        int left = 0, right = 0;
        int sum = 0;
        while (right < nums.length) {
            sum += nums[right];
            while (sum > goal) {
                sum -= nums[left];
                left++;
            }
            if (sum == goal) {
                count += (right - left + 1);
            }
            right++;
        }
        return count;
    }
}
