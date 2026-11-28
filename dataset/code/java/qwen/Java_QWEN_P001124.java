import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int src = sc.nextInt();
        int dst = sc.nextInt();
        int k = sc.nextInt();
        
        int[][] dp = new int[k + 2][n];
        for (int[] row : dp) Arrays.fill(row, Integer.MAX_VALUE / 2);
        dp[0][src] = 0;
        
        List<int[]> edges = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            int w = sc.nextInt();
            edges.add(new int[]{u, v, w});
        }
        
        for (int i = 1; i <= k + 1; i++) {
            for (int[] e : edges) {
                int u = e[0], v = e[1], w = e[2];
                if (dp[i - 1][u] != Integer.MAX_VALUE / 2) {
                    dp[i][v] = Math.min(dp[i][v], dp[i - 1][u] + w);
                }
            }
        }
        
        int ans = Integer.MAX_VALUE / 2;
        for (int i = 0; i <= k + 1; i++) {
            ans = Math.min(ans, dp[i][dst]);
        }
        System.out.println(ans == Integer.MAX_VALUE / 2 ? -1 : ans);
    }
}
