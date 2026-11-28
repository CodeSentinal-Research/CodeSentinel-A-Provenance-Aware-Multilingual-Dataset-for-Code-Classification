import java.util.*;
public class Main {
    static int n;
    static int[][] maze;
    static boolean[][] visited;
    static List<String> paths;
    static int[] dr = {1, 0, 0, -1};
    static int[] dc = {0, -1, 1, 0};
    static char[] dir = {'D', 'L', 'R', 'U'};
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        maze = new int[n][n];
        visited = new boolean[n][n];
        paths = new ArrayList<>();
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) maze[i][j] = sc.nextInt();
        if(maze[0][0] == 1) {
            visited[0][0] = true;
            backtrack(0, 0, new StringBuilder());
        }
        for(String p : paths) System.out.println(p);
    }
    static void backtrack(int r, int c, StringBuilder path) {
        if(r == n-1 && c == n-1) {
            paths.add(path.toString());
            return;
        }
        for(int i=0; i<4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if(nr >= 0 && nr < n && nc >= 0 && nc < n && maze[nr][nc] == 1 && !visited[nr][nc]) {
                visited[nr][nc] = true;
                path.append(dir[i]);
                backtrack(nr, nc, path);
                path.deleteCharAt(path.length() - 1);
                visited[nr][nc] = false;
            }
        }
    }
}
