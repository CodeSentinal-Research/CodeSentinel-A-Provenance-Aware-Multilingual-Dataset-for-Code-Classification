import java.util.*;
public class Main {
    static int n, k;
    static int[] nums;
    static int minMaxSum;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();
        nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        minMaxSum = Integer.MAX_VALUE;
        int[] sums = new int[k];
        backtrack(0, sums);
        System.out.println(minMaxSum);
    }
    
    static void backtrack(int idx, int[] sums) {
        if(idx == n) {
            int maxVal = 0;
            for(int s : sums) maxVal = Math.max(maxVal, s);
            minMaxSum = Math.min(minMaxSum, maxVal);
            return;
        }
        
        int maxVal = 0;
        for(int s : sums) maxVal = Math.max(maxVal, s);
        if(maxVal >= minMaxSum) return;
        
        for(int i=0; i<k; i++) {
            sums[i] += nums[idx];
            backtrack(idx+1, sums);
            sums[i] -= nums[idx];
            if(sums[i] == 0) break;
        }
    }
}
