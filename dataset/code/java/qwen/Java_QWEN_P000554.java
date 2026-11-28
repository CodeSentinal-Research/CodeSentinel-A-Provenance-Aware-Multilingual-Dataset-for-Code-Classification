import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        char[][] maze = new char[m][n];
        for(int i=0; i<m; i++) maze[i] = sc.next().toCharArray();
        int sr = sc.nextInt(), scCol = sc.nextInt();
        
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{sr, scCol, 0});
        boolean[][] visited = new boolean[m][n];
        visited[sr][scCol] = true;
        int[][] dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        while(!queue.isEmpty()) {
            int[] curr = queue.poll();
            int r = curr[0], c = curr[1], dist = curr[2];
            if((r == 0 || r == m - 1 || c == 0 || c == n - 1) && !(r == sr && c == scCol)) {
                System.out.println(dist); return;
            }
            for(int[] d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                if(nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc] && maze[nr][nc] == '.') {
                    visited[nr][nc] = true;
                    queue.offer(new int[]{nr, nc, dist + 1});
                }
            }
        }
        System.out.println(-1);
    }
}
