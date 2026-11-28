import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] board = new int[n][n];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) board[i][j] = sc.nextInt();
        
        int[] flats = new int[n * n + 1];
        int idx = 1;
        boolean leftToRight = true;
        for(int i=n-1; i>=0; i--) {
            if(leftToRight) {
                for(int j=0; j<n; j++) flats[idx++] = board[i][j];
            } else {
                for(int j=n-1; j>=0; j--) flats[idx++] = board[i][j];
            }
            leftToRight = !leftToRight;
        }
        
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{1, 0});
        boolean[] visited = new boolean[n * n + 1];
        visited[1] = true;
        
        while(!queue.isEmpty()) {
            int[] curr = queue.poll();
            int pos = curr[0], moves = curr[1];
            if(pos == n * n) { System.out.println(moves); return; }
            for(int i=1; i<=6; i++) {
                int next = pos + i;
                if(next <= n * n) {
                    int dest = flats[next] == -1 ? next : flats[next];
                    if(!visited[dest]) {
                        visited[dest] = true;
                        queue.offer(new int[]{dest, moves + 1});
                    }
                }
            }
        }
        System.out.println(-1);
    }
}
