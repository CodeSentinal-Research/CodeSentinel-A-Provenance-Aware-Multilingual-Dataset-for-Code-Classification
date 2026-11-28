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

        System.out.println(maxSubarraySumCircular(nums));
    }

    public static int maxSubarraySumCircular(int[] nums) {
        int total = 0, max = nums[0], currMax = 0;
        int min = 0, currMin = 0;

        for (int num : nums) {
            total += num;
            currMax = Math.max(currMax + num, num);
            currMin = Math.min(currMin + num, num);
            max = Math.max(max, currMax);
            min = Math.min(min, currMin);
        }

        if (max < 0) return max;

        return Math.max(max, total - min);
    }
}
