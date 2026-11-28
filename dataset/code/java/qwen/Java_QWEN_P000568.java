import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int y = sc.nextInt();
        x = Math.abs(x); y = Math.abs(y);
        
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0, 0, 0});
        Set<String> visited = new HashSet<>();
        visited.add("0,0");
        
        while(!queue.isEmpty()) {
            int[] curr = queue.poll();
            int cx = curr[0], cy = curr[1], steps = curr[2];
            if(cx == x && cy == y) { System.out.println(steps); return; }
            
            int[][] moves = {{1,2}, {2,1}, {-1,2}, {2,-1}, {1,-2}, {-2,1}, {-1,-2}, {-2,-1}};
            for(int[] m : moves) {
                int nx = cx + m[0], ny = cy + m[1];
                String key = nx + "," + ny;
                if(!visited.contains(key) && nx >= -300 && nx <= 300 && ny >= -300 && ny <= 300) {
                    visited.add(key);
                    queue.offer(new int[]{nx, ny, steps + 1});
                }
            }
        }
    }
}
