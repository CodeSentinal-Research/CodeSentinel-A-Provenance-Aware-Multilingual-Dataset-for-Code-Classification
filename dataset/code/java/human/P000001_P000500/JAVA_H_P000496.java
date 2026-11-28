package programs.dp;

import java.util.Stack;

/**
 * LeetCode 907: Sum of Subarray Minimums
 * Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr.
 * Since the answer may be large, return the answer modulo 10^9 + 7.
 */
public class SumSubarrayMinimums {

    public int sumSubarrayMins(int[] arr) {
        if (arr == null || arr.length == 0) {
            return 0;
        }
        
        int MOD = 1_000_000_007;
        int n = arr.length;
        long result = 0;
        
        Stack<Integer> stack = new Stack<>();
        int[] left = new int[n];
        int[] right = new int[n];
        
        // Find previous less element
        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && arr[stack.peek()] >= arr[i]) {
                stack.pop();
            }
            left[i] = stack.isEmpty() ? -1 : stack.peek();
            stack.push(i);
        }
        
        stack.clear();
        
        // Find next less element
        for (int i = n - 1; i >= 0; i--) {
            while (!stack.isEmpty() && arr[stack.peek()] > arr[i]) {
                stack.pop();
            }
            right[i] = stack.isEmpty() ? n : stack.peek();
            stack.push(i);
        }
        
        // Calculate sum
        for (int i = 0; i < n; i++) {
            long count = (long) (i - left[i]) * (right[i] - i);
            result = (result + count * arr[i]) % MOD;
        }
        
        return (int) result;
    }

    public static void main(String[] args) {
        SumSubarrayMinimums solution = new SumSubarrayMinimums();
        
        // Test cases
        System.out.println("Sum of subarray minimums for [3,1,2,4]: " + 
            solution.sumSubarrayMins(new int[]{3, 1, 2, 4})); // 17
        System.out.println("Sum of subarray minimums for [11,81,94,43,3]: " + 
            solution.sumSubarrayMins(new int[]{11, 81, 94, 43, 3})); // 444
    }
}
