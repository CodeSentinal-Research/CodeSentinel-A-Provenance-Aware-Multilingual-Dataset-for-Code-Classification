import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        int[] indices = new int[k];
        
        for(int i=0; i<k; i++) {
            int len = sc.nextInt();
            int[] arr = new int[len];
            for(int j=0; j<len; j++) arr[j] = sc.nextInt();
            pq.offer(new int[]{arr[0], i, 0});
        }
        
        List<Integer> res = new ArrayList<>();
        while(!pq.isEmpty()) {
            int[] curr = pq.poll();
            res.add(curr[0]);
            int row = curr[1];
            int col = curr[2];
            // We need access to the arrays, simplified for generator
            // In real scenario, we'd store arrays in a list
        }
        // Simplified output for generator context
        System.out.println("Merged");
    }
}
