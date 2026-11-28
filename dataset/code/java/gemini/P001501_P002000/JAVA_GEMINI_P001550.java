import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), k = sc.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = sc.nextInt();

            for (int i = 0; i <= n - k; i++) {
                int[] win = Arrays.copyOfRange(nums, i, i + k);
                Arrays.sort(win);
                long sum = 0;
                for (int a = 0; a < k; a++) {
                    for (int b = a + 1; b < k; b++) {
                        sum += Math.abs(win[a] - win[b]);
                    }
                }
                System.out.print(sum + " ");
            }
            System.out.println();
        }
        sc.close();
    }
}