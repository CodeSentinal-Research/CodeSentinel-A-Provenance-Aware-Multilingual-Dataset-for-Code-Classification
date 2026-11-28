import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> Long.compare((long)b[0]*b[0]+(long)b[1]*b[1], (long)a[0]*a[0]+(long)a[1]*a[1]));
        
        for(int i=0; i<n; i++) {
            int x = sc.nextInt();
            int y = sc.nextInt();
            pq.offer(new int[]{x, y});
            if(pq.size() > k) pq.poll();
        }
        
        while(!pq.isEmpty()) {
            int[] p = pq.poll();
            System.out.println(p[0] + " " + p[1]);
        }
    }
}
