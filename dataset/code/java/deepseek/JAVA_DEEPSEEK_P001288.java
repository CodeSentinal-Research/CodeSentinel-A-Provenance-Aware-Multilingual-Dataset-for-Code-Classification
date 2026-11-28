import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        scanner.close();
        System.out.println(maxSum(nums, k));
    }

    private static int maxSum(int[] nums, int k) {
        int n = nums.length;
        for (int i = 0; i < n && k > 0; i++) {
            if (nums[i] < 0) {
                nums[i] = -nums[i];
                k--;
            }
        }
        if (k % 2 != 0) {
            int maxIndex = findMaxIndex(nums);
            nums[maxIndex] = -nums[maxIndex];
        }
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        return sum;
    }

    private static int findMaxIndex(int[] nums) {
        int maxIndex = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }
        return maxIndex;
    }
}
