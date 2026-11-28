import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        for(int i=0; i<k; i++) pq.offer(new int[]{nums[i], i});
        
        for(int i=k; i<n; i++) {
            if(nums[i] > pq.peek()[0]) {
                pq.poll();
                pq.offer(new int[]{nums[i], i});
            }
            // Remove expired
            while(!pq.isEmpty() && pq.peek()[1] <= i-k) pq.poll();
            
            System.out.print(pq.peek()[0] + " ");
        }
        // Print first k-1 windows? No, problem says every window
        // Re-implementing properly
        pq.clear();
        for(int i=0; i<n; i++) {
            pq.offer(new int[]{nums[i], i});
            while(pq.peek()[1] <= i-k) pq.poll();
            if(i >= k-1) System.out.print(pq.peek()[0] + " ");
        }
    }
}
