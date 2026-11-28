import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        int[][] forest = new int[m][n];
        List<int[]> trees = new ArrayList<>();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                forest[i][j] = sc.nextInt();
                if(forest[i][j] > 1) trees.add(new int[]{forest[i][j], i, j});
            }
        }
        
        trees.sort((a, b) -> a[0] - b[0]);
        int sx = 0, sy = 0, steps = 0;
        for(int[] tree : trees) {
            int dist = bfs(forest, sx, sy, tree[1], tree[2], m, n);
            if(dist == -1) { System.out.println(-1); return; }
            steps += dist;
            sx = tree[1]; sy = tree[2];
        }
        System.out.println(steps);
    }
    static int bfs(int[][] forest, int sr, int sc, int tr, int tc, int m, int n) {
        if(sr == tr && sc == tc) return 0;
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{sr, sc, 0});
        boolean[][] visited = new boolean[m][n];
        visited[sr][sc] = true;
        int[][] dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!queue.isEmpty()) {
            int[] curr = queue.poll();
            for(int[] d : dirs) {
                int r = curr[0] + d[0], c = curr[1] + d[1];
                if(r >= 0 && r < m && c >= 0 && c < n && !visited[r][c] && forest[r][c] != 0) {
                    if(r == tr && c == tc) return curr[2] + 1;
                    visited[r][c] = true;
                    queue.offer(new int[]{r, c, curr[2] + 1});
                }
            }
        }
        return -1;
    }
}
