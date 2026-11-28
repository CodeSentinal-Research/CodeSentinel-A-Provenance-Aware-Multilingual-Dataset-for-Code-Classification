import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            int[][] board = new int[n][n];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) board[i][j] = scanner.nextInt();
            }
            int[] arr = new int[n * n + 1];
            int cur = 1;
            for (int r = n - 1; r >= 0; r--) {
                if ((n - 1 - r) % 2 == 0) {
                    for (int c = 0; c < n; c++) arr[cur++] = board[r][c];
                } else {
                    for (int c = n - 1; c >= 0; c--) arr[cur++] = board[r][c];
                }
            }
            Queue<int[]> q = new LinkedList<>();
            boolean[] vis = new boolean[n * n + 1];
            q.add(new int[]{1, 0});
            vis[1] = true;
            int ans = -1;
            while (!q.isEmpty()) {
                int[] p = q.poll();
                int pos = p[0], moves = p[1];
                if (pos == n * n) { ans = moves; break; }
                for (int step = 1; step <= 6; step++) {
                    int nxt = pos + step;
                    if (nxt <= n * n) {
                        int dest = (arr[nxt] != -1) ? arr[nxt] : nxt;
                        if (!vis[dest]) {
                            vis[dest] = true;
                            q.add(new int[]{dest, moves + 1});
                        }
                    }
                }
            }
            System.out.println(ans);
        }
    }
}