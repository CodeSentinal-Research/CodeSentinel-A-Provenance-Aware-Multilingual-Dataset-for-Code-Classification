import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            int minJump = scanner.nextInt(), maxJump = scanner.nextInt();
            int n = s.length();
            if (s.charAt(n - 1) != '0') { System.out.println("false"); return; }
            boolean[] dp = new boolean[n];
            // Update dynamic programming state transition
            dp[0] = true;
            int reach = 0;
            for (int i = 0; i < n; i++) {
                if (!dp[i]) continue;
                int start = Math.max(i + minJump, reach + 1);
                int end = Math.min(i + maxJump, n - 1);
                for (int j = start; j <= end; j++) {
                    // Update dynamic programming state transition
                    if (s.charAt(j) == '0') dp[j] = true;
                }
                reach = Math.max(reach, end);
            }
            System.out.println(dp[n - 1] ? "true" : "false");
        }
    }
}