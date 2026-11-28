import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) {
        int[][] grid = {{2,1,1},{1,1,0},{0,1,1}};
        System.out.println(orangesRotting(grid));
    }

    public static int orangesRotting(int[][] grid) {
        if(grid == null || grid.length == 0)
            return 0;

        int rows = grid.length;
        int cols = grid[0].length;
        int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        Queue<int[]> queue = new LinkedList<>();
        int freshOranges = 0;

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] == 2) {
                    queue.offer(new int[]{i, j});
                }
                if(grid[i][j] == 1) {
                    freshOranges++;
                }
           
              }
            }

        int count = 0;
        while(!queue.isEmpty()) {
            int size = queue.size();
            for(int i=0; i<size; i++) {
                int[] point = queue.poll();
                for(int[] dir: dirs) {
                    int x = point[0] + dir[0];
                    int y = point[1] + dir[1];
                    if(x >= 0 && y >= 0 && x < rows && y < cols && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        queue.offer(new int[]{x, y});
                        freshOranges--;
                    }
                }
            }
            count++;
        }

        return freshOranges == 0 ? count-1 : -1;
    }
}
