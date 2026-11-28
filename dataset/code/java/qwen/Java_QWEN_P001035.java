import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[][] matrix = new int[n][n];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) matrix[i][j] = sc.nextInt();
            
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        for(int i=0; i<n; i++) pq.offer(new int[]{matrix[i][0], i, 0});
        
        int res = 0;
        for(int i=0; i<k; i++) {
            int[] curr = pq.poll();
            res = curr[0];
            if(curr[2] + 1 < n) {
                pq.offer(new int[]{matrix[curr[1]][curr[2]+1], curr[1], curr[2]+1});
            }
        }
        System.out.println(res);
    }
}
