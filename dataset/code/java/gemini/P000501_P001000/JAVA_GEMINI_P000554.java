import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int m = scanner.nextInt(), n = scanner.nextInt();
            String[] maze = new String[m];
            for (int i = 0; i < m; i++) maze[i] = scanner.next();
            int er = scanner.nextInt(), ec = scanner.nextInt();
            Queue<int[]> q = new LinkedList<>();
            boolean[][] vis = new boolean[m][n];
            q.add(new int[]{er, ec, 0});
            vis[er][ec] = true;
            int[] dr = {-1, 1, 0, 0}, dc = {0, 0, -1, 1};
            int ans = -1;
            while (!q.isEmpty()) {
                int[] cur = q.poll();
                int r = cur[0], c = cur[1], d = cur[2];
                if ((r != er || c != ec) && (r == 0 || r == m - 1 || c == 0 || c == n - 1)) {
                    ans = d; break;
                }
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i], nc = c + dc[i];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && maze[nr].charAt(nc) == '.' && !vis[nr][nc]) {
                        vis[nr][nc] = true;
                        q.add(new int[]{nr, nc, d + 1});
                    }
                }
            }
            System.out.println(ans);
        }
    }
}