import java.util.Scanner;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextInt()) {
            int r = scanner.nextInt(), c = scanner.nextInt();
            int[][] grid = new int[r][c];
            for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++)
                    grid[i][j] = scanner.nextInt();
            for (int j = 0; j < c; j++) {
                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < r; i++) {
                    if (i > 0) sb.append(' ');
                    sb.append(grid[i][j]);
                }
                System.out.println(sb.toString());
            }
        }
    }
}