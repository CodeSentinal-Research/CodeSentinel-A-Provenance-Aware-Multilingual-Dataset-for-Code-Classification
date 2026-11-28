import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    private static int[][] dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    private static class Cell implements Comparable<Cell> {
        int x, y, effort;
        Cell(int x, int y, int effort) {
            this.x = x;
            this.y = y;
            this.effort = effort;
        }
        public int compareTo(Cell o) {
            return effort - o.effort;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int R = sc.nextInt();
        int C = sc.nextInt();
        int[][] grid = new int[R][C];
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                grid[i][j] = sc.nextInt();
        System.out.println(minEffortPath(grid));
    }

    public static int minEffortPath(int[][] grid) {
        int R = grid.length, C = grid[0].length;
        boolean[][] visited = new boolean[R][C];
        PriorityQueue<Cell> pq = new PriorityQueue<>();
        pq.offer(new Cell(0, 0, 0));
        int[][] effort = new int[R][C];
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                effort[i][j] = Integer.MAX_VALUE;
        effort[0][0] = 0;
        while (!pq.isEmpty()) {
            Cell cur = pq.poll();
            if (cur.x == R - 1 && cur.y == C - 1)
                return cur.effort;
            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dir[i][0], ny = cur.y + dir[i][1];
                if (nx >= 0 && nx < R && ny >= 0 && ny < C && !visited[nx][ny]) {
                    int newEffort = Math.max(effort[cur.x][cur.y], Math.abs(grid[nx][ny] - grid[cur.x][cur.y]));
                    if (newEffort < effort[nx][ny]) {
                        effort[nx][ny] = newEffort;
                        pq.offer(new Cell(nx, ny, newEffort));
                    }
                }
            }
            visited[cur.x][cur.y] = true;
        }
        return -1;
    }
}
