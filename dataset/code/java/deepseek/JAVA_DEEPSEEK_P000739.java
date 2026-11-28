import java.util.Scanner;

public class Main {
    public static int countPaths(int[][] maze, int n, int m) {
        if (maze[0][0] == 0 || maze[n-1][m-1] == 0) {
            return 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (maze[i][j] == 1) {
                    maze[i][j] = 0;
                    if (i < n-1) {
                        maze[i+1][j] += maze[i][j];
                    }
                    if (j < m-1) {
                        maze[i][j+1] += maze[i][j];
                    }
                }
            }
        }
        return maze[n-1][m-1];
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int[][] maze = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maze[i][j] = scanner.nextInt();
            }
        }
        System.out.println(countPaths(maze, n, m));
    }
}
