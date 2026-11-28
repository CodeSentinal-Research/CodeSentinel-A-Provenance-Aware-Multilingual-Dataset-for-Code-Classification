import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int k = sc.nextInt();
        
        long[] dp = new long[s.length()+1];
        dp[0] = 1;
        
        for(int i=1; i<=s.length(); i++) {
            long num = 0;
            for(int j=i; j>=1; j--) {
                num = num * 10 + (s.charAt(j-1) - '0');
                if(num > k) break;
                if(s.charAt(j-1) != '0') {
                    dp[i] = (dp[i] + dp[j-1]) % 1000000007;
                }
            }
        }
        System.out.println(dp[s.length()]);
    }
}
