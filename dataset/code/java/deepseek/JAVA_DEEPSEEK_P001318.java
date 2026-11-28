import java.util.Scanner;

public class Main {
    private static final int[][] directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    private static char[][] grid;
    private static String target;
    private static int r, c, targetLength;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        r = scanner.nextInt();
        c = scanner.nextInt();
        scanner.nextLine();
        grid = new char[r][c];
        for (int i = 0; i < r; i++) {
            String line = scanner.nextLine();
            for (int j = 0; j < c; j++) {
                grid[i][j] = line.charAt(j);
            }
        }
        target = scanner.nextLine();
        targetLength = target.length();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (dfs(i, j)) {
                    System.out.println("YES");
                    return;
                }
            }
        }
        System.out.println("NO");
    }

    private static boolean dfs(int x, int y) {
        if (grid[x][y] != target.charAt(0)) {
            return false;
        }
        if (targetLength == 1) {
            return true;
        }
        char temp = grid[x][y];
        grid[x][y] = '0';
        for (int[] dir : directions) {
            int newX = x + dir[0];
            int newY = y + dir[1];
            if (newX >= 0 && newX < r && newY >= 0 && newY < c && grid[newX][newY] == target.charAt(1)) {
                if (dfs(newX, newY)) {
                    return true;
                }
            }
        }
        grid[x][y] = temp;
        return false;
    }
}
