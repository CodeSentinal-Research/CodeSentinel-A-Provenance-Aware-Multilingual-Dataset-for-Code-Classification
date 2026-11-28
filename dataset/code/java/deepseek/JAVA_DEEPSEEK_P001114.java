import java.util.*;

public class Main {
    static int[][] dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    static int R, C;
    static char[][] grid;
    static Queue<int[]> q = new LinkedList<>();

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        R = sc.nextInt();
        C = sc.nextInt();
        grid = new char[R][C];
        int fresh = 0;
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                grid[i][j] = sc.next().charAt(0);
                if (grid[i][j] == 'F') fresh++;
                if (grid[i][j] == 'R') q.offer(new int[]{i, j});
            }
        }
        if (fresh == 0) {
            System.out.println(0);
            return;
        }
        int ans = bfs();
        if (ans == -1) System.out.println(-1);
        else System.out.println(ans);
    }

    public static int bfs() {
        int[][] dist = new int[R][C];
        for (int i = 0; i < R; i++) Arrays.fill(dist[i], -1);
        while (!q.isEmpty()) {
            int[] cur = q.poll();
            for (int i = 0; i < 4; i++) {
                int nr = cur[0] + dir[i][0];
                int nc = cur[1] + dir[i][1];
                if (nr < 0 || nr >= R || nc < 0 || nc >= C || dist[nr][nc] != -1 || grid[nr][nc] == 'F') continue;
                if (grid[nr][nc] == 'R') return dist[cur[0]][cur[1]] + 1;
                dist[nr][nc] = dist[cur[0]][cur[1]] + 1;
                q.offer(new int[]{nr, nc});
            }
        }
        return -1;
    }
}
