import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        long totalSum = 0;
        for (int i = 0; i < n; i++) {
            nums[i] = sc.nextInt();
            totalSum += nums[i];
        }
        
        long maxKadane = nums[0];
        long currentKadane = nums[0];
        for (int i = 1; i < n; i++) {
            currentKadane = Math.max((long)nums[i], currentKadane + nums[i]);
            maxKadane = Math.max(maxKadane, currentKadane);
        }
        
        long minKadane = nums[0];
        long currentMin = nums[0];
        for (int i = 1; i < n; i++) {
            currentMin = Math.min((long)nums[i], currentMin + nums[i]);
            minKadane = Math.min(minKadane, currentMin);
        }
        
        long maxCircular = totalSum - minKadane;
        
        // If all numbers are negative, maxCircular will be 0 (empty subarray), which is invalid for circular max unless we allow empty.
        // Standard problem assumes non-empty.
        if (totalSum == minKadane) {
             System.out.println(maxKadane);
        } else {
             System.out.println(Math.max(maxKadane, maxCircular));
        }
    }
}
