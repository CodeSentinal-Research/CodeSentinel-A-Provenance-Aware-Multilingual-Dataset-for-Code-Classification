import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        String s = br.readLine();
        int n = Integer.parseInt(br.readLine());
        Set<String> dict = new HashSet<>();
        for (int i = 0; i < n; i++) {
            dict.add(br.readLine());
        }

        out.println(canSegment(s, dict) ? "YES" : "NO");
        out.close();
    }

    private static boolean canSegment(String s, Set<String> dict) {
        boolean[] dp = new boolean[s.length() + 1];
        dp[0] = true;
        for (int i = 1; i <= s.length(); i++) {
            if (dp[i]) {
                for (String word : dict) {
                    int len = word.length();
                    if (i - len >= 0 && s.substring(i - len, i).equals(word)) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.length()];
    }
}
