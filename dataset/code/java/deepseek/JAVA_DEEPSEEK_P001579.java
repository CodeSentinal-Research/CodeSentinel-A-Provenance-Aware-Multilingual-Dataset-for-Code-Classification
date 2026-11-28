import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int[] nums = new int[N];
        for (int i = 0; i < N; i++) {
            nums[i] = scanner.nextInt();
        }
        scanner.close();
        System.out.println(maxNegatives(nums, K));
    }

    private static int maxNegatives(int[] nums, int k) {
        int count = 0;
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] < 0 && count < k) {
                count++;
                max = Math.max(max, nums[i]);
            } else if (nums[i] < 0) {
                count = 1;
                max = nums[i];
            } else if (nums[i] >= 0) {
                count = 0;
            }
        }
        return count;
    }
}
