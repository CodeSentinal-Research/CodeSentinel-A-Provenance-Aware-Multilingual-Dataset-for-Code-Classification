import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = sc.nextInt();

            long ops = 0;
            for (int i = 1; i < n; i++) {
                ops += Math.abs(nums[i] - nums[i - 1]);
            }
            System.out.println(ops);
        }
        sc.close();
    }
}