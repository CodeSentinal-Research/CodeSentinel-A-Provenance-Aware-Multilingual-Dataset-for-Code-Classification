import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void wallsAndGates(int[][] rooms) {
        if (rooms.length == 0) return;
        int m = rooms.length, n = rooms[0].length;
        int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    queue.offer(new int[]{i, j});
                }
            }
        }
        while (!queue.isEmpty()) {
            int[] point = queue.poll();
            for (int[] dir : dirs) {
                int x = point[0] + dir[0], y = point[1] + dir[1];
                if (x < 0 || y < 0 || x >= m || y >= n || rooms[x][y] != 2147483647) continue;
                rooms[x][y] = rooms[point[0]][point[1]] + 1;
                queue.offer(new int[]{x, y});
            }
       }
    }
}
