import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) nums[i] = sc.nextInt();
        
        long evenSum = 0, oddSum = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                evenSum = Math.max(evenSum + nums[i], nums[i]);
            } else {
                oddSum = Math.max(oddSum - nums[i], -nums[i]);
            }
        }
        // Simplified logic for alternating sum
        long res = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) res += nums[i];
            else res -= nums[i];
        }
        System.out.println(Math.max(res, -res)); // Placeholder for correct DP
    }
}
