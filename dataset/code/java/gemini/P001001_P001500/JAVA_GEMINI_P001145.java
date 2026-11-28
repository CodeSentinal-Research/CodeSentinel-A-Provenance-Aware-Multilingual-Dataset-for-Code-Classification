import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = sc.nextInt();

            int[] inc = new int[n];
            for (int i = 0; i < n; i++) {
                inc[i] = 1;
                for (int j = 0; j < i; j++) {
                    if (nums[j] < nums[i]) inc[i] = Math.max(inc[i], inc[j] + 1);
                }
            }

            int[] dec = new int[n];
            for (int i = n - 1; i >= 0; i--) {
                dec[i] = 1;
                for (int j = n - 1; j > i; j--) {
                    if (nums[j] < nums[i]) dec[i] = Math.max(dec[i], dec[j] + 1);
                }
            }

            int ans = 0;
            for (int i = 0; i < n; i++) {
                ans = Math.max(ans, inc[i] + dec[i] - 1);
            }
            System.out.println(ans);
        }
        sc.close();
    }
}