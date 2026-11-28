public class Solution {
    public int majorityElement(int[] nums) {
        int candidate = nums[0];
        int count = 0;
        for (int x : nums) {
            if (count == 0) candidate = x;
            count += (x == candidate ? 1 : -1);
        }
        return candidate;
    }
}

import java.util.Scanner;

class MainExecution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (!scanner.hasNextInt()) {
            return;
        }
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        Solution solution = new Solution();
        System.out.println(solution.majorityElement(nums));
    }
}
