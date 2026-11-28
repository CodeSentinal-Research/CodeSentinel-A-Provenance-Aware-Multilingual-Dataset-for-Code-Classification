import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        int n = scanner.nextInt();
        int[][] grid = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[i][j] = scanner.nextInt();
            }
        }
        System.out.println(minCellsVisited(grid));
    }

    private static int minCellsVisited(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] directions = {{0, 1}, {1, 0}};
        boolean[][] visited = new boolean[m][n];
        PriorityQueue<int[]> queue = new PriorityQueue<>((a, b) -> a[2] - b[2]);
        queue.offer(new int[]{0, 0, 0});
        while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            if (cell[0] == m - 1 && cell[1] == n - 1) {
                return cell[2];
            }
            if (visited[cell[0]][cell[1]]) {
                continue;
            }
            visited[cell[0]][cell[1]] = true;
            for (int[] dir : directions) {
                int ni = cell[0] + dir[0] * grid[cell[0]][cell[1]];
                int nj = cell[1] + dir[1] * grid[cell[0]][cell[1]];
                if (ni < m && nj < n) {
                    queue.offer(new int[]{ni, nj, cell[2] + 1});
                }
            }
        }
        return -1;
    }
}
