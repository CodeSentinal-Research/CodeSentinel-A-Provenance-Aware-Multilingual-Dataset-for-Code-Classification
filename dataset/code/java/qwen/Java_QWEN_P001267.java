import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int bricks = sc.nextInt();
        int ladders = sc.nextInt();
        int[] heights = new int[n];
        for(int i=0; i<n; i++) heights[i] = sc.nextInt();
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int i = 0;
        for(; i < n-1; i++) {
            int diff = heights[i+1] - heights[i];
            if(diff > 0) {
                pq.offer(diff);
                if(pq.size() > ladders) {
                    bricks -= pq.poll();
                }
                if(bricks < 0) break;
            }
        }
        System.out.println(i);
    }
}
