import java.util.Arrays;
import java.util.Scanner;

public class Solution {
    public static int aggressiveCows(int[] stalls, int k) {
        Arrays.sort(stalls);
        int left = 1, right = stalls[stalls.length - 1] - stalls[0];
        int ans = 1;
        // Binary search loop to narrow down range
        while (left <= right) {
            // Calculate midpoint to prevent potential overflow
            int mid = left + (right - left) / 2;
            int cows = 1, last = stalls[0];
            for (int i = 1; i < stalls.length; i++) {
                if (stalls[i] - last >= mid) {
                    cows++;
                    last = stalls[i];
                }
            }
            if (cows >= k) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int[] stalls = new int[n];
            for (int i = 0; i < n; i++) stalls[i] = sc.nextInt();
            System.out.println(aggressiveCows(stalls, k));
        }
        sc.close();
    }
}