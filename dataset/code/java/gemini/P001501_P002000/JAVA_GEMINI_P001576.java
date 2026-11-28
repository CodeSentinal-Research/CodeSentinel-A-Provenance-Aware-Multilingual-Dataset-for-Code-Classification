import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), k = sc.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = sc.nextInt();

            int zeros = 0;
            for (int i = 0; i < k; i++) if (nums[i] == 0) zeros++;
            int ans = zeros > 0 ? 1 : 0;

            for (int i = k; i < n; i++) {
                if (nums[i] == 0) zeros++;
                if (nums[i - k] == 0) zeros--;
                if (zeros > 0) ans++;
            }
            System.out.println(ans);
        }
        sc.close();
    }
}