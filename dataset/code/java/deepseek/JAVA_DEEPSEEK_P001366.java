import java.util.Scanner;

public class Main {
    private static int[][] directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    private static char[][] grid;
    private static int startX, startY, endX, endY;
    private static int totalEmptySquares;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int R = scanner.nextInt();
        int C = scanner.nextInt();
        scanner.nextLine();

        grid = new char[R][C];
        for (int i = 0; i < R; i++) {
            String line = scanner.nextLine();
            for (int j = 0; j < C; j++) {
                grid[i][j] = line.charAt(j);
                if (grid[i][j] == 'S') {
                    startX = i;
                    startY = j;
                } else if (grid[i][j] == 'E') {
                    endX = i;
                    endY = j;
                } else if (grid[i][j] == 'X') {
                    totalEmptySquares++;
                }
            }
        }

        backtrack(startX, startY, 1);
        System.out.println(totalPaths);
    }

    private static void backtrack(int x, int y, int paths) {
        if (x == endX && y == endY) {
            totalPaths = Math.max(totalPaths, paths);
            return;
        }

        grid[x][y] = 'V';
        for (int[] dir : directions) {
            int newX = x + dir[0];
            int newY = y + dir[1];
            if (isValidMove(newX, newY) && grid[newX][newY] != 'X' && grid[newX][newY] != 'V') {
                backtrack(newX, newY, paths + 1);
            }
        }
        grid[x][y] = 'X';
    }

    private static boolean isValidMove(int x, int y) {
        return x >= 0 && x < grid.length && y >= 0 && y < grid[0].length;
    }

    private static int totalPaths = 0;
}
