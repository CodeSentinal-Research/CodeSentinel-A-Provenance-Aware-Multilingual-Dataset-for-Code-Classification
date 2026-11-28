import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int m = scanner.nextInt(), n = scanner.nextInt();
            int[][] forest = new int[m][n];
            List<int[]> trees = new ArrayList<>();
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < n; c++) {
                    forest[r][c] = scanner.nextInt();
                    if (forest[r][c] > 1) trees.add(new int[]{forest[r][c], r, c});
                }
            }
            trees.sort((a, b) -> a[0] - b[0]);
            int total = 0, curR = 0, curC = 0;
            int[] dr = {-1, 1, 0, 0}, dc = {0, 0, -1, 1};
            for (int[] t : trees) {
                int tr = t[1], tc = t[2];
                int steps = -1;
                if (curR == tr && curC == tc) {
                    steps = 0;
                } else {
                    Queue<int[]> q = new LinkedList<>();
                    boolean[][] vis = new boolean[m][n];
                    q.add(new int[]{curR, curC, 0});
                    vis[curR][curC] = true;
                    while (!q.isEmpty()) {
                        int[] cur = q.poll();
                        if (cur[0] == tr && cur[1] == tc) { steps = cur[2]; break; }
                        for (int i = 0; i < 4; i++) {
                            int nr = cur[0] + dr[i], nc = cur[1] + dc[i];
                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && forest[nr][nc] != 0 && !vis[nr][nc]) {
                                vis[nr][nc] = true;
                                q.add(new int[]{nr, nc, cur[2] + 1});
                            }
                        }
                    }
                }
                if (steps == -1) { System.out.println(-1); return; }
                total += steps;
                curR = tr; curC = tc;
            }
            System.out.println(total);
        }
    }
}