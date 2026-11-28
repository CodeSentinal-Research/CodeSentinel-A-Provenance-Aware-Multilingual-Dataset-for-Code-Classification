import java.util.Scanner;

public class Main {
    private static char[][] grid;
    private static boolean[][] visited;
    private static int n;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        scanner.nextLine();

        grid = new char[n][n];
        visited = new boolean[n][n];

        for (int i = 0; i < n; i++) {
            String line = scanner.nextLine();
            for (int j = 0; j < n; j++) {
                grid[i][j] = line.charAt(j);
           
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == ' ' && !visited[i][j]) {
                    dfs(i, j);
                    count++;
                }
            }
        }

        System.out.println(count);
    }

    private static void dfs(int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == ' ' || visited[i][j]) {
            return;
        }

        visited[i][j] = true;
        dfs(i - 1, j);
        dfs(i + 1, j);
        dfs(i, j - 1);
        dfs(i, j + 1);
    }
}
