import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] board = new int[n*n+1];
        for(int i = 1; i < n*n; i++) {
            board[i] = i;
        }
        int ladders = scanner.nextInt();
        for(int i = 0; i < ladders; i++) {
            int start = scanner.nextInt();
            int end = scanner.nextInt();
            board[start] = end;
        }
        int snakes = scanner.nextInt();
        for(int i = 0; i < snakes; i++) {
            int start = scanner.nextInt();
            int end = scanner.nextInt();
            board[start] = end;
        }
        System.out.println(minMoves(board, n*n));
    }

    public static int minMoves(int[] board, int n) {
        Queue<Integer> queue = new LinkedList<>();
        boolean[] visited = new boolean[n+1];
        queue.offer(1);
        visited[1] = true;
        int moves = 0;
        while(!queue.isEmpty()) {
            int size = queue.size();
            while(size-- > 0) {
                int cur = queue.poll();
                if(cur == n) {
                    return moves;
                }
                for(int i = 1; i <= 6 && cur + i <= n; i++) {
                    if(!visited[cur + i]) {
                        visited[cur + i] = true;
                        queue.offer(board[cur + i]);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
}
