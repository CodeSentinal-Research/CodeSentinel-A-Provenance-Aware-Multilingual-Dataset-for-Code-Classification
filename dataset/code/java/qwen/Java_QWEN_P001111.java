import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int l = sc.nextInt();
        
        int[] board = new int[n * n + 1];
        for (int i = 0; i < l; i++) {
            int start = sc.nextInt();
            int end = sc.nextInt();
            board[start] = end;
        }
        
        int s = sc.nextInt();
        for (int i = 0; i < s; i++) {
            int head = sc.nextInt();
            int tail = sc.nextInt();
            board[head] = tail;
        }
        
        boolean[] visited = new boolean[n * n + 1];
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{1, 0});
        visited[1] = true;
        
        while (!q.isEmpty()) {
            int[] curr = q.poll();
            int pos = curr[0];
            int moves = curr[1];
            
            if (pos == n * n) {
                System.out.println(moves);
                return;
            }
            
            for (int i = 1; i <= 6; i++) {
                int next = pos + i;
                if (next <= n * n && !visited[next]) {
                    visited[next] = true;
                    if (board[next] != 0) {
                        q.offer(new int[]{board[next], moves + 1});
                    } else {
                        q.offer(new int[]{next, moves + 1});
                    }
                }
            }
        }
        System.out.println(-1);
    }
}
