import java.util.Scanner;
public class Solution {
    public int missingNumber(int[] nums, int n) {
        long expected = (long)n*(n+1)/2, actual = 0;
        for (int x : nums) actual += x;
        return (int)(expected - actual);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); int[] nums = new int[n-1];
        for (int i = 0; i < n-1; i++) nums[i] = sc.nextInt();
        System.out.println(new Solution().missingNumber(nums, n));
    }
}
