import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        int minDiff = Integer.MAX_VALUE;
        int maxVal = Integer.MIN_VALUE;
        int minVal = Integer.MAX_VALUE;
        
        for(int i=0; i<k; i++) {
            maxVal = Math.max(maxVal, nums[i]);
            minVal = Math.min(minVal, nums[i]);
        }
        minDiff = maxVal - minVal;
        
        for(int i=k; i<n; i++) {
            // Recompute max/min for window is O(K), using deque is better but for simplicity:
            maxVal = Integer.MIN_VALUE;
            minVal = Integer.MAX_VALUE;
            for(int j=i-k+1; j<=i; j++) {
                maxVal = Math.max(maxVal, nums[j]);
                minVal = Math.min(minVal, nums[j]);
            }
            minDiff = Math.min(minDiff, maxVal - minVal);
        }
        System.out.println(minDiff);
    }
}
