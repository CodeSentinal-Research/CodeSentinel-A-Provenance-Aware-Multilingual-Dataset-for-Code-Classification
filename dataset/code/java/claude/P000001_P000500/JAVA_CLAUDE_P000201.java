import java.util.*;
public class Solution {
    public int maxSumIncreasingSubseq(int[] arr) {
        int n = arr.length; int[] dp = arr.clone();
        for (int i = 1; i < n; i++)
            for (int j = 0; j < i; j++)
                if (arr[j] < arr[i]) dp[i] = Math.max(dp[i], dp[j] + arr[i]);
        return Arrays.stream(dp).max().getAsInt();
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(); int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
        System.out.println(new Solution().maxSumIncreasingSubseq(arr));
    }
}
