import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), k = sc.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = sc.nextInt();

            int curNegs = 0;
            for (int i = 0; i < k; i++) if (nums[i] < 0) curNegs++;
            int maxNegs = curNegs;

            for (int i = k; i < n; i++) {
                if (nums[i] < 0) curNegs++;
                if (nums[i - k] < 0) curNegs--;
                maxNegs = Math.max(maxNegs, curNegs);
            }
            System.out.println(maxNegs);
        }
        sc.close();
    }
}