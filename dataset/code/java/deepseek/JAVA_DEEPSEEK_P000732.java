import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
    static int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    static String[] directionStr = {"R", "D", "L", "U"};

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[][] maze = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                maze[i][j] = scanner.nextInt();
            }
        }
        List<String> result = new ArrayList<>();
        if (findPath(maze, n, 0, 0, "", result)) {
            result.forEach(System.out::println);
        } else {
            System.out.println("NO PATH FOUND");
        }
    }

    private static boolean findPath(int[][] maze, int n, int x, int y, String path, List<String> result) {
        if (x == n - 1 && y == n - 1 && maze[x][y] == 1) {
            result.add(path);
            return false;
        }
        if (maze[x][y] == 0) {
            return false;
        }
        maze[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];
            if (newX >= 0 && newX < n && newY >= 0 && newY < n) {
                if (findPath(maze, n, newX, newY, path + directionStr[i], result)) {
                    return true;
                }
           }
        }
        maze[x][y] = 1;
        return false;
    }
}
