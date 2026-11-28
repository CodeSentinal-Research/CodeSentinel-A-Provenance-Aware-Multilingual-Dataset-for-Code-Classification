import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), k = sc.nextInt(), d = sc.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = sc.nextInt();

            long curSum = 0;
            for (int i = 0; i < k; i++) curSum += nums[i];
            int ans = curSum % d == 0 ? 1 : 0;

            for (int i = k; i < n; i++) {
                curSum += nums[i] - nums[i - k];
                if (curSum % d == 0) ans++;
            }
            System.out.println(ans);
        }
        sc.close();
    }
}