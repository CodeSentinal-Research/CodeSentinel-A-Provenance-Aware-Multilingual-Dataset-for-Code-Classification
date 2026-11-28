import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int x = Math.abs(scanner.nextInt()), y = Math.abs(scanner.nextInt());
            Queue<int[]> q = new LinkedList<>();
            q.add(new int[]{0, 0, 0});
            boolean[][] vis = new boolean[x + 10][y + 10];
            vis[4][4] = true;
            int[] dr = {-2, -2, -1, -1, 1, 1, 2, 2};
            int[] dc = {-1, 1, -2, 2, -2, 2, -1, 1};
            int ans = 0;
            while (!q.isEmpty()) {
                int[] cur = q.poll();
                int r = cur[0], c = cur[1], d = cur[2];
                if (r == x && c == y) { ans = d; break; }
                for (int i = 0; i < 8; i++) {
                    int nr = r + dr[i], nc = c + dc[i];
                    if (nr >= -2 && nr <= x + 2 && nc >= -2 && nc <= y + 2) {
                        if (!vis[nr + 4][nc + 4]) {
                            vis[nr + 4][nc + 4] = true;
                            q.add(new int[]{nr, nc, d + 1});
                        }
                    }
                }
            }
            System.out.println(ans);
        }
    }
}