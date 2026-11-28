import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = s.length();
        boolean[][] isPalin = new boolean[n][n];
        int[] dp = new int[n+1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<=i; j++) {
                if(s.charAt(i) == s.charAt(j) && (i - j <= 2 || isPalin[j+1][i-1])) {
                    isPalin[j][i] = true;
                    if(j == 0) dp[i+1] = 1;
                    else if(dp[j] != Integer.MAX_VALUE) {
                        dp[i+1] = Math.min(dp[i+1], dp[j] + 1);
                    }
                }
            }
        }
        System.out.println(dp[n] - 1);
    }
}
