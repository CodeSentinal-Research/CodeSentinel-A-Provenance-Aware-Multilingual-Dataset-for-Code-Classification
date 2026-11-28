import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), k = sc.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = sc.nextInt();

            int nonInc = 0;
            for (int i = 0; i < k - 1; i++) if (nums[i] >= nums[i + 1]) nonInc++;
            int ans = nonInc == 0 ? 1 : 0;

            for (int i = k; i < n; i++) {
                if (nums[i - 1] >= nums[i]) nonInc++;
                if (nums[i - k] >= nums[i - k + 1]) nonInc--;
                if (nonInc == 0) ans++;
            }
            System.out.println(ans);
        }
        sc.close();
    }
}