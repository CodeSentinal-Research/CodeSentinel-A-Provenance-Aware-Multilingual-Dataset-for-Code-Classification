import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        int[][] grid = new int[m][n];
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++) grid[i][j] = sc.nextInt();
        
        int[][] dist = new int[m][n];
        for(int[] row : dist) Arrays.fill(row, Integer.MAX_VALUE);
        dist[0][0] = 1;
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0, 0});
        
        while(!queue.isEmpty()) {
            int[] curr = queue.poll();
            int r = curr[0], c = curr[1];
            int jump = grid[r][c];
            if(jump == 0) continue;
            
            for(int i=1; i<=jump; i++) {
                if(c + i < n && dist[r][c+i] > dist[r][c] + 1) {
                    dist[r][c+i] = dist[r][c] + 1;
                    queue.offer(new int[]{r, c+i});
                }
                if(r + i < m && dist[r+i][c] > dist[r][c] + 1) {
                    dist[r+i][c] = dist[r][c] + 1;
                    queue.offer(new int[]{r+i, c});
                }
            }
        }
        System.out.println(dist[m-1][n-1] == Integer.MAX_VALUE ? -1 : dist[m-1][n-1]);
    }
}
