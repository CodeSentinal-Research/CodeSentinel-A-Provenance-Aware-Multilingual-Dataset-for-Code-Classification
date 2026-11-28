import java.util.*;
public class Solution {
    static long countSubseqSum(int[] arr, int idx, int curSum, int target) {
        if (idx == arr.length) return curSum == target ? 1 : 0;
        return countSubseqSum(arr, idx + 1, curSum, target) + countSubseqSum(arr, idx + 1, curSum + arr[idx], target);
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = scanner.nextInt();
            int target = scanner.nextInt();
            System.out.println(countSubseqSum(nums, 0, 0, target));
        }
    }
}