import java.util.*;

public class Main {
    static int R, C, N;
    static String[] words;
    static char[][] crossword;
    static boolean[][] visited;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        R = sc.nextInt();
        C = sc.nextInt();
        sc.nextLine();
        crossword = new char[R][C];
        visited = new boolean[R][C];
        for (int i = 0; i < R; i++) {
            crossword[i] = sc.nextLine().toCharArray();
        }
        N = sc.nextInt();
        sc.nextLine();
        words = new String[N];
        for (int i = 0; i < N; i++) {
            words[i] = sc.nextLine();
        }
        sc.close();

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (crossword[i][j] == '.' && dfs(i, j)) {
                    System.out.println("YES");
                    return;
                }
            }
        }
        System.out.println("NO");
    }

    static boolean dfs(int r, int c) {
        if (r < 0 || r >= R || c < 0 || c >= C || visited[r][c]) {
            return false;
        }
        visited[r][c] = true;
        if (r > 0 && crossword[r - 1][c] == '.' && dfs(r - 1, c)) {
            return true;
        }
        if (c > 0 && crossword[r][c - 1] == '.' && dfs(r, c - 1)) {
            return true;
        }
        if (r < R - 1 && crossword[r + 1][c] == '.' && dfs(r + 1, c)) {
            return true;
        }
        if (c < C - 1 && crossword[r][c + 1] == '.' && dfs(r, c + 1)) {
            return true;
        }
        return false;
    }
}
