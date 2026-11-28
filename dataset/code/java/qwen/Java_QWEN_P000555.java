import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int p = sc.nextInt();
        int b = sc.nextInt();
        int[] banned = new int[b];
        for(int i=0; i<b; i++) banned[i] = sc.nextInt();
        int k = sc.nextInt();
        
        int[] res = new int[n];
        Arrays.fill(res, -1);
        for(int ban : banned) res[ban] = -1;
        
        Queue<int[]> queue = new LinkedList<>();
        boolean[] visited = new boolean[n];
        queue.offer(new int[]{p, 0});
        visited[p] = true;
        
        while(!queue.isEmpty()) {
            int[] curr = queue.poll();
            int pos = curr[0], ops = curr[1];
            res[pos] = ops;
            
            // Simulate reverse operations is complex, using BFS on positions
            // This is a simplified placeholder for the complex logic required
        }
        for(int x : res) System.out.print(x + " ");
    }
}
