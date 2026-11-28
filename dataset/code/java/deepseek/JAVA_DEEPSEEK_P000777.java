import java.util.*;

public class Main {
    private static final String[][] grid = new String[20][20];
    private static final String[] words = new String[20];
    private static int N, W;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        W = scanner.nextInt();
        scanner.nextLine();
        for (int i = 0; i < N; i++) {
            String line = scanner.nextLine();
            for (int j = 0; j < N; j++) {
                grid[i][j] = String.valueOf(line.charAt(j));
            }
        }
        for (int i = 0; i < W; i++) {
            words[i] = scanner.nextLine();
        }
        if (solve(0, 0, 0)) {
            printGrid();
        } else {
            System.out.println("No solution exists");
        }
    }

    private static boolean solve(int idx, int x, int y) {
        if (idx == W) {
            return true;
        }
        for (int i = x; i < N; i++) {
            for (int j = (i == x ? y : 0); j <= N - words[idx].length(); j++) {
                if (canPlaceWord(i, j, words[idx], true) || canPlaceWord(i, j, words[idx], false)) {
                    if (solve(idx + 1, i == N - 1 ? 0 : i + 1, i == N - 1 ? j + 1 : j)) {
                        return true;
                    }
                    unplaceWord(i, j, words[idx], true);
                    unplaceWord(i, j, words[idx], false);
                }
            }
        }
        return false;
    }

    private static boolean canPlaceWord(int x, int y, String word, boolean horizontal) {
        if (horizontal) {
            for (int i = 0; i < word.length(); i++) {
                if (y + i < N && (grid[x][y + i].equals("#") || (y + i < N - 1 && grid[x][y + i + 1].equals("#")))) {
                    return false;
                }
            }
            return true;
        } else {
            for (int i = 0; i < word.length(); i++) {
                if (x + i < N && (grid[x + i][y].equals("#") || (x + i < N - 1 && grid[x + i + 1][y].equals("#")))) {
                    return false;
                }
            }
            return true;
        }
    }

    private static void unplaceWord(int x, int y, String word, boolean horizontal) {
        if (horizontal) {
            for (int i = 0; i < word.length(); i++) {
                grid[x][y + i] = word.charAt(i) == '#' ? "#" : ".";
            }
        } else {
            for (int i = 0; i < word.length(); i++) {
                grid[x + i][y] = word.charAt(i) == '#' ? "#" : ".";
            }
        }
    }

    private static void printGrid() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(grid[i][j]);
            }
            System.out.println();
        }
    }
}
