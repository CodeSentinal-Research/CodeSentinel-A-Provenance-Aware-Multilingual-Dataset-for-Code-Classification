import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int R = scanner.nextInt();
        int C = scanner.nextInt();
        char[][] grid = new char[R][C];
        for (int i = 0; i < R; i++) {
            String line = scanner.next();
            for (int j = 0; j < C; j++) {
                grid[i][j] = line.charAt(j);
            }
        }
        scanner.close();

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (i == 0 || i == R - 1 || j == 0 || j == C - 1) {
                    if (grid[i][j] == 'O') {
                        grid[i][j] = 'X';
                    }
                } else {
                    if (grid[i][j] == 'O') {
                        grid[i][j] = 'X';
                    }
                }
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                System.out.print(grid[i][j]);
            }
            System.out.println();
        }
    }
}
