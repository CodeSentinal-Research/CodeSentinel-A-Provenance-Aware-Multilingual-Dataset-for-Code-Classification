import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), k = sc.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = sc.nextInt();

            int nonPos = 0;
            for (int i = 0; i < k; i++) if (nums[i] <= 0) nonPos++;
            int ans = nonPos == 0 ? 1 : 0;

            for (int i = k; i < n; i++) {
                if (nums[i] <= 0) nonPos++;
                if (nums[i - k] <= 0) nonPos--;
                if (nonPos == 0) ans++;
            }
            System.out.println(ans);
        }
        sc.close();
    }
}