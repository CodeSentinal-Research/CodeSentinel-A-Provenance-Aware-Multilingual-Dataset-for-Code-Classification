public class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        res[0] = 1;
        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= suffix;
            suffix *= nums[i];
        }
        return res;
    }
}

import java.util.Scanner;

class MainExecution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) {
                nums[i] = scanner.nextInt();
            }
            Solution solution = new Solution();
            int[] result = solution.productExceptSelf(nums);
            for (int i = 0; i < result.length; i++) {
                System.out.print(result[i] + (i == result.length - 1 ? "" : " "));
            }
            System.out.println();
        }
        scanner.close();
    }
}
