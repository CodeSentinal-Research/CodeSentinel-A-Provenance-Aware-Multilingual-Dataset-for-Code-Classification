import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt(), k = sc.nextInt();
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) nums[i] = sc.nextInt();

            long curProd = 1;
            for (int i = 0; i < k; i++) curProd *= nums[i];
            long maxProd = curProd;

            for (int i = k; i < n; i++) {
                curProd = (curProd / nums[i - k]) * nums[i];
                maxProd = Math.max(maxProd, curProd);
            }
            System.out.println(maxProd);
        }
        sc.close();
    }
}