import java.util.Scanner;

public class Solution {
    private static long minDiff = Long.MAX_VALUE;

    private static void backtrack(int[] arr, int idx, int count, long curSum, long totalSum, int halfSize) {
        if (count == halfSize) {
            long diff = Math.abs(totalSum - 2 * curSum);
            minDiff = Math.min(minDiff, diff);
            return;
        }
        if (idx == arr.length) return;

        backtrack(arr, idx + 1, count + 1, curSum + arr[idx], totalSum, halfSize);
        backtrack(arr, idx + 1, count, curSum, totalSum, halfSize);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int[] arr = new int[n];
            long totalSum = 0;
            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
                totalSum += arr[i];
            }
            backtrack(arr, 0, 0, 0, totalSum, n / 2);
            System.out.println(minDiff);
        }
        sc.close();
    }
}