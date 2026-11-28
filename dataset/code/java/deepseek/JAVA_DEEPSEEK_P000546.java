import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        int minJump = scanner.nextInt();
        int maxJump = scanner.nextInt();

        System.out.println(new Solution().canReach(s, minJump, maxJump));
    }
}

class Solution {
    public boolean canReach(String s, int minJump, int maxJump) {
        int n = s.length();
        boolean[] dp = new boolean[n];
        dp[0] = true;
        int maxReachableIndex = 0;

        for (int i = 1; i < n; i++) {
            if (i > maxReachableIndex) {
                break;
            }
            if (s.charAt(i) == '0') {
                if (maxReachableIndex < i + maxJump) {
                    maxReachableIndex = Math.max(maxReachableIndex, i + minJump - 1);
                    for (int j = i; j <= maxReachableIndex && j < n; j++) {
                        dp[j] = dp[i] || dp[j];
                    }
                }
            }
        }

        return dp[n - 1];
    }
}
