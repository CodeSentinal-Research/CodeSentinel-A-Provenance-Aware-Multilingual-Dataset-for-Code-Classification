import java.util.Scanner;

public class Solution {
    public static long paintersPartition(int[] arr, int k) {
        long left = 0, right = 0;
        for (int x : arr) {
            left = Math.max(left, x);
            right += x;
        }
        long ans = right;
        // Binary search loop to narrow down range
        while (left <= right) {
            // Calculate midpoint to prevent potential overflow
            long mid = left + (right - left) / 2;
            int painters = 1;
            long curr = 0;
            for (int x : arr) {
                if (curr + x > mid) {
                    painters++;
                    curr = x;
                } else {
                    curr += x;
                }
            }
            if (painters <= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
            System.out.println(paintersPartition(arr, k));
        }
        sc.close();
    }
}