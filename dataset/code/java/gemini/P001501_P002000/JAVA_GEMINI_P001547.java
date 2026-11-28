import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), k = sc.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = sc.nextInt();

            int curOdds = 0;
            for (int i = 0; i < k; i++) if (nums[i] % 2 != 0) curOdds++;
            int maxOdds = curOdds;

            for (int i = k; i < n; i++) {
                if (nums[i] % 2 != 0) curOdds++;
                if (nums[i - k] % 2 != 0) curOdds--;
                maxOdds = Math.max(maxOdds, curOdds);
            }
            System.out.println(maxOdds);
        }
        sc.close();
    }
}