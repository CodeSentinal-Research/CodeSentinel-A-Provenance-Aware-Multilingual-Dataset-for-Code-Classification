import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        int n = scanner.nextInt();
        int entranceRow = scanner.nextInt();
        int entranceCol = scanner.nextInt();

        char[][] maze = new char[m][n];
        for (int i = 0; i < m; i++) {
            maze[i] = scanner.next().toCharArray();
        }

        System.out.println(nearestExit(maze, entranceRow, entranceCol));
    }

    private static int nearestExit(char[][] maze, int entranceRow, int entranceCol) {
        int m = maze.length;
        int n = maze[0].length;
        int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{entranceRow, entranceCol, 0});
        maze[entranceRow][entranceCol] = '+';

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            for (int[] dir : directions) {
                int newRow = current[0] + dir[0];
                int newCol = current[1] + dir[1];
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n) {
                    if (maze[newRow][newCol] == '.') {
                        if (newRow == 0 || newRow == m - 1 || newCol == 0 || newCol == n - 1) {
                            return current[2] + 1;
                        }
                        queue.offer(new int[]{newRow, newCol, current[2] + 1});
                        maze[newRow][newCol] = '+';
                    }
                }
            }
        }

        return -1;
    }
}
