import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0; i<n; i++) arr[i] = sc.nextInt();
        
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int i=0; i<=k; i++) pq.offer(arr[i]);
        
        int idx = 0;
        for(int i=k+1; i<n; i++) {
            arr[idx++] = pq.poll();
            pq.offer(arr[i]);
        }
        while(!pq.isEmpty()) arr[idx++] = pq.poll();
        
        for(int x : arr) System.out.print(x + " ");
    }
}
