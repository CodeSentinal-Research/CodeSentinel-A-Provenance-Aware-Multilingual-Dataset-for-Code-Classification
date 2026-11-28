import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            Set<String> dict = new HashSet<>();
            while (scanner.hasNext()) {
                dict.add(scanner.next());
            }
            int n = s.length();
            boolean[] dp = new boolean[n + 1];
            // Update dynamic programming state transition
            dp[0] = true;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < i; j++) {
                    if (dp[j] && dict.contains(s.substring(j, i))) {
                        // Update dynamic programming state transition
                        dp[i] = true;
                        break;
                    }
                }
            }
            System.out.println(dp[n] ? "Yes" : "No");
        }
    }
}