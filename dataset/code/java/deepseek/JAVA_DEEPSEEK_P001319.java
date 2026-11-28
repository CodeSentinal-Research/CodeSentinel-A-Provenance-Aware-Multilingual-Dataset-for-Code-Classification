import java.util.*;

public class Main {
    private static final int[][] dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    private static Set<String> res = new HashSet<>();
    private static boolean[][] visited;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int R = scanner.nextInt();
        int C = scanner.nextInt();
        scanner.nextLine();
        char[][] grid = new char[R][C];
        for (int i = 0; i < R; i++) {
            String line = scanner.nextLine();
            for (int j = 0; j < C; j++) {
                grid[i][j] = line.charAt(j);
            }
        }
        int N = scanner.nextInt();
        scanner.nextLine();
        List<String> words = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            words.add(scanner.nextLine());
        }
        visited = new boolean[R][C];
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (visited[i][j]) continue;
                visited[i][j] = true;
                dfs(grid, i, j, words, "");
                visited[i][j] = false;
            }
        }
        List<String> result = new ArrayList<>(res);
        Collections.sort(result);
        for (String s : result) {
            System.out.println(s);
        }
    }

    private static void dfs(char[][] grid, int x, int y, List<String> words, String word) {
        if (word.length() == words.get(0).length()) {
            res.add(word);
            return;
        }
        for (int[] d : dir) {
            int newX = x + d[0];
            int newY = y + d[1];
            if (newX >= 0 && newX < grid.length && newY >= 0 && newY < grid[0].length && !visited[newX][newY] && words.contains(word + grid[newX][newY])) {
                visited[newX][newY] = true;
                dfs(grid, newX, newY, words, word + grid[newX][newY]);
                visited[newX][newY] = false;
            }
        }
    }
}
