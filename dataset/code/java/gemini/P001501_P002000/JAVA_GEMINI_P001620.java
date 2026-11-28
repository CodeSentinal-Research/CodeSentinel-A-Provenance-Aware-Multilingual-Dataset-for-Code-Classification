import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), l = sc.nextInt(), r = sc.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = sc.nextInt();

            long sum = 0;
            for (int i = l; i <= r; i += 2) sum += nums[i];
            System.out.println(sum);
        }
        sc.close();
    }
}