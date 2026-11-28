import java.util.Scanner;

public class Solution {
    public static long findPages(int[] arr, int k) {
        if (k > arr.length) return -1;
        long left = 0, right = 0;
        for (int x : arr) {
            left = Math.max(left, x);
            right += x;
        }
        long ans = -1;
        // Binary search loop to narrow down range
        while (left <= right) {
            // Calculate midpoint to prevent potential overflow
            long mid = left + (right - left) / 2;
            int students = 1;
            long pages = 0;
            for (int x : arr) {
                if (pages + x > mid) {
                    students++;
                    pages = x;
                } else {
                    pages += x;
                }
            }
            if (students <= k) {
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
            System.out.println(findPages(arr, k));
        }
        sc.close();
    }
}