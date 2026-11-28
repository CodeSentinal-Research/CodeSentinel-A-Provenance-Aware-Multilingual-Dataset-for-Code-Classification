import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int moves = sc.nextInt();
            int[] board = new int[31];
            Arrays.fill(board, -1);
            for (int i = 0; i < moves; i++) {
                int u = sc.nextInt(), v = sc.nextInt();
                board[u] = v;
            }
            boolean[] vis = new boolean[31];
            Queue<int[]> q = new LinkedList<>();
            q.offer(new int[]{1, 0});
            vis[1] = true;
            int ans = -1;

            while (!q.isEmpty()) {
                int[] cur = q.poll();
                int pos = cur[0], steps = cur[1];
                if (pos == 30) {
                    ans = steps;
                    break;
                }
                for (int d = 1; d <= 6; d++) {
                    int next = pos + d;
                    if (next <= 30) {
                        if (board[next] != -1) next = board[next];
                        if (!vis[next]) {
                            vis[next] = true;
                            q.offer(new int[]{next, steps + 1});
                        }
                    }
                }
            }
            System.out.println(ans);
        }
        sc.close();
    }
}