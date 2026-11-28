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
        System.out.println(maxConsecutiveOnesIII(nums, k));
    }

    public static int maxConsecutiveOnesIII(int[] nums, int k) {
        int left = 0, right = 0, maxOnes = 0, maxZeroes = 0, maxLen = 0;
        while (right < nums.length) {
            if (nums[right] == 1) {
                maxOnes++;
            } else {
                maxZeroes++;
            }
            while (maxZeroes > k) {
                if (nums[left] == 0) {
                    maxZeroes--;
                }
                if (nums[left] == 1) {
                    maxOnes--;
                }
                left++;
            }
            maxLen = Math.max(maxLen, maxOnes + maxZeroes);
            right++;
        }
        return maxLen;
    }
}
