import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        
        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        for(int x : arr) {
            pq.offer(x);
            if(pq.size() > k) pq.poll();
        }
        
        while(!pq.isEmpty()) System.out.print(pq.poll() + " ");
    }
}
