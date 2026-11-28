import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    private static int[][] directions = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    private static class Cell implements Comparable<Cell> {
        int x, y, dist;
        Cell(int x, int y, int dist) {
            this.x = x;
            this.y = y;
            this.dist = dist;
        }
        public int compareTo(Cell other) {
            return dist - other.dist;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        char[][] matrix = new char[n][n];
        for (int i = 0; i < n; i++) {
            matrix[i] = scanner.nextLine().toCharArray();
        }
        int[][] dist = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = Integer.MAX_VALUE;
            }
        }
        Queue<Cell> queue = new PriorityQueue<>();
        queue.offer(new Cell(0, 0, matrix[0][0] == '0' ? 0 : 1));
        while (!queue.isEmpty()) {
            Cell cell = queue.poll();
            if (cell.x == n - 1 && cell.y == n - 1) {
                System.out.println(cell.dist);
                return;
            }
            for (int[] dir : directions) {
                int nx = cell.x + dir[0], ny = cell.y + dir[1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && dist[nx][ny] > cell.dist + (matrix[nx][ny] == '0' ? 0 : 1)) {
                    dist[nx][ny] = cell.dist + (matrix[nx][ny] == '0' ? 0 : 1);
                    queue.offer(new Cell(nx, ny, dist[nx][ny]));
                }
            }
        }
        System.out.println(-1);
    }
}
