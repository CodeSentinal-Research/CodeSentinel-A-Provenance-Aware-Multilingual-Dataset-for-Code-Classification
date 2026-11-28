import java.util.*;
public class Main {
    static int n;
    static int[] nums;
    static int minDiff;
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        minDiff = Integer.MAX_VALUE;
        boolean[] used = new boolean[n];
        backtrack(0, 0, 0, used);
        System.out.println(minDiff);
    }
    
    static void backtrack(int idx, int sum1, int sum2, boolean[] used) {
        if(idx == n) {
            minDiff = Math.min(minDiff, Math.abs(sum1 - sum2));
            return;
        }
        
        // Pruning
        if(Math.abs(sum1 - sum2) >= minDiff) return;
        
        used[idx] = true;
        backtrack(idx+1, sum1 + nums[idx], sum2, used);
        used[idx] = false;
        
        used[idx] = true;
        backtrack(idx+1, sum1, sum2 + nums[idx], used);
        used[idx] = false;
    }
}
