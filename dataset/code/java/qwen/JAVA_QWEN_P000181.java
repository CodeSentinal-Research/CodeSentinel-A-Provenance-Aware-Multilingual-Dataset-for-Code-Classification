import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int l = sc.nextInt();
        int m = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
        }
        
        // Prefix sums for subarrays of length L and M
        long[] prefix = new long[n + 1];
        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }
        
        long maxSum = Long.MIN_VALUE;
        
        // Case 1: L comes before M
        for (int i = l; i <= n - m; i++) {
            long sumL = prefix[i] - prefix[i-l];
            long sumM = prefix[i+m] - prefix[i];
            maxSum = Math.max(maxSum, sumL + sumM);
        }
        
        // Case 2: M comes before L
        for (int i = m; i <= n - l; i++) {
            long sumM = prefix[i] - prefix[i-m];
            long sumL = prefix[i+l] - prefix[i];
            maxSum = Math.max(maxSum, sumM + sumL);
        }
        
        System.out.println(maxSum);
    }
}
