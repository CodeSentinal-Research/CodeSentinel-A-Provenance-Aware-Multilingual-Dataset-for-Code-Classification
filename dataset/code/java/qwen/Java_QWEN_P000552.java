import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        int[][] rooms = new int[m][n];
        Queue<int[]> queue = new LinkedList<>();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                rooms[i][j] = sc.nextInt();
                if(rooms[i][j] == 0) queue.offer(new int[]{i, j});
            }
        }
        
        int[][] dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        while(!queue.isEmpty()) {
            int[] curr = queue.poll();
            for(int[] d : dirs) {
                int r = curr[0] + d[0], c = curr[1] + d[1];
                if(r >= 0 && r < m && c >= 0 && c < n && rooms[r][c] == 2147483647) {
                    rooms[r][c] = rooms[curr[0]][curr[1]] + 1;
                    queue.offer(new int[]{r, c});
                }
            }
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                System.out.print(rooms[i][j] + " ");
            }
            System.out.println();
        }
    }
}
