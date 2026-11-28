import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), k = sc.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = sc.nextInt();

            double curSum = 0;
            for (int i = 0; i < k; i++) curSum += nums[i];
            System.out.printf("%.2f ", curSum / k);

            for (int i = k; i < n; i++) {
                curSum += nums[i] - nums[i - k];
                System.out.printf("%.2f ", curSum / k);
            }
            System.out.println();
        }
        sc.close();
    }
}