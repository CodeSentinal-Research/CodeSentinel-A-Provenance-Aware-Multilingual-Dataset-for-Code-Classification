import java.util.*;
public class Main {
    static int[] nums;
    static Integer[][] memo;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        nums = new int[n];
        int sum = 0;
        for(int i=0; i<n; i++) {
            nums[i] = sc.nextInt();
            sum += nums[i];
        }
        memo = new Integer[n][n];
        int p1 = solve(0, n-1);
        System.out.println(p1 >= sum - p1 ? "true" : "false");
    }
    static int solve(int i, int j) {
        if(i > j) return 0;
        if(memo[i][j] != null) return memo[i][j];
        
        int pickLeft = nums[i] + Math.min(solve(i+2, j), solve(i+1, j-1));
        int pickRight = nums[j] + Math.min(solve(i, j-2), solve(i+1, j-1));
        
        memo[i][j] = Math.max(pickLeft, pickRight);
        return memo[i][j];
    }
}
