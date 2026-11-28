import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println(getMaxLength(nums));
    }

    private static int getMaxLength(int[] nums) {
        int n = nums.length;
        int[] prefixSum = new int[n + 1];
        int[] suffixSum = new int[n + 1];
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + nums[i] % 2;
            suffixSum[n - i - 1] = suffixSum[n - i] + nums[n - i - 1] % 2;
        }
        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            if (prefixSum[i + 1] == suffixSum[i]) {
                maxLength = Math.max(maxLength, i + 1);
            }
        }
        return maxLength;
    }
}
