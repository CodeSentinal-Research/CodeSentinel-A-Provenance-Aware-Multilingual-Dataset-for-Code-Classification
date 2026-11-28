import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] grid = new int[n][n];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) grid[i][j] = sc.nextInt();
        
        // State: row, col, horizontal/vertical
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0, 0, 0, 0}); // r, c, orientation (0=H, 1=V), moves
        boolean[][][] visited = new boolean[n][n][2];
        visited[0][0][0] = true;
        
        while(!queue.isEmpty()) {
            int[] curr = queue.poll();
            int r = curr[0], c = curr[1], ori = curr[2], moves = curr[3];
            if(r == n - 1 && c == n - 2 && ori == 0) { System.out.println(moves); return; }
            
            // Move Right
            if(c + 2 < n && grid[r][c+2] == 0 && !visited[r][c+1][ori]) {
                visited[r][c+1][ori] = true;
                queue.offer(new int[]{r, c+1, ori, moves+1});
            }
            // Move Down
            if(r + 1 < n && grid[r+1][c] == 0 && grid[r+1][c+1] == 0 && !visited[r+1][c][ori]) {
                 visited[r+1][c][ori] = true;
                 queue.offer(new int[]{r+1, c, ori, moves+1});
            }
            // Rotate
            if(ori == 0 && r + 1 < n && grid[r+1][c] == 0 && grid[r+1][c+1] == 0 && !visited[r][c][1]) {
                visited[r][c][1] = true;
                queue.offer(new int[]{r, c, 1, moves+1});
            } else if(ori == 1 && c + 1 < n && grid[r][c+1] == 0 && grid[r+1][c+1] == 0 && !visited[r][c][0]) {
                visited[r][c][0] = true;
                queue.offer(new int[]{r, c, 0, moves+1});
            }
        }
        System.out.println(-1);
    }
}
