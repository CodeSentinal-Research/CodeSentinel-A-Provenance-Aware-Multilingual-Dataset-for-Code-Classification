import java.util.*;

public class Main {
    static class Pair {
        int x, y, d, dir;
        Pair(int x, int y, int d, int dir) {
            this.x = x;
            this.y = y;
            this.d = d;
            this.dir = dir;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] grid = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = sc.nextInt();
            }
        }
        System.out.println(minMoves(grid));
    }

    public static int minMoves(int[][] grid) {
        int n = grid.length;
        boolean[][][][] visited = new boolean[n][n][n][4];
        Queue<Pair> queue = new LinkedList<>();
        queue.offer(new Pair(0, 0, 0, 0));
        visited[0][0][0][0] = true;
        while (!queue.isEmpty()) {
            Pair cur = queue.poll();
            if (cur.x == n - 1 && cur.y == n - 1) {
                return cur.d;
            }
            for (int i = 0; i < 4; i++) {
                int nx = cur.x, ny = cur.y, nd = cur.d;
                if (i < 2) {
                    nx += i == 0 ? 0 : 1;
                    ny += i == 0 ? 1 : 0;
                    nd++;
                } else {
                    int ndir = (cur.dir + (i == 2 ? 1 : -1) + 4) % 4;
                    nx += ">v<^".charAt(ndir) == '>' ? 1 : (ndir == 'v' ? -1 : 0);
                    ny += ">v<^".charAt(ndir) == 'v' ? 1 : (ndir == '<' ? -1 : 0);
                    nd++;
                }
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0 && !visited[nx][ny][nd][(cur.dir + (i < 2 ? 0 : (i == 3 ? -1 : 1))) % 4]) {
                    queue.offer(new Pair(nx, ny, nd, (cur.dir + (i < 2 ? 0 : (i == 3 ? -1 : 1))) % 4));
                    visited[nx][ny][nd][(cur.dir + (i < 2 ? 0 : (i == 3 ? -1 : 1))) % 4] = true;
                }
            }
        }
        return -1;
    }
}
