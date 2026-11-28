import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int m = sc.nextInt(), n = sc.nextInt();
            int[][] mat = new int[m][n];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) mat[i][j] = sc.nextInt();
            }

            int maxSum = Integer.MIN_VALUE;

            for (int left = 0; left < n; left++) {
                int[] rowSum = new int[m];
                for (int right = left; right < n; right++) {
                    for (int i = 0; i < m; i++) rowSum[i] += mat[i][right];

                    int curMax = rowSum[0];
                    int curSum = 0;
                    for (int x : rowSum) {
                        curSum = Math.max(x, curSum + x);
                        curMax = Math.max(curMax, curSum);
                    }
                    maxSum = Math.max(maxSum, curMax);
                }
            }
            System.out.println(maxSum);
        }
        sc.close();
    }
}