import java.util.*;
public class Main {
    static int N, M;
    static int[][] grid;
    static boolean[][] visited;
    static int[] dr = {1, 0, 0, -1};
    static int[] dc = {0, -1, 1, 0};
    static char[] dir = {'D', 'L', 'R', 'U'};
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        M = sc.nextInt();
        grid = new int[N][M];
        visited = new boolean[N][M];
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++) grid[i][j] = sc.nextInt();
        if(grid[0][0] == 1) {
            visited[0][0] = true;
            backtrack(0, 0, new StringBuilder());
        }
    }
    static void backtrack(int r, int c, StringBuilder path) {
        if(r == N-1 && c == M-1) {
            System.out.println(path.toString());
            return;
        }
        for(int i=0; i<4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr >= 0 && nr < N && nc >= 0 && nc < M && grid[nr][nc] == 1 && !visited[nr][nc]) {
                visited[nr][nc] = true;
                path.append(dir[i]);
                backtrack(nr, nc, path);
                path.deleteCharAt(path.length() - 1);
                visited[nr][nc] = false;
            }
        }
    }
}
