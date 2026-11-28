import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] barcodes = new int[n];
        for(int i=0; i<n; i++) barcodes[i] = sc.nextInt();
        
        Map<Integer, Integer> freq = new HashMap<>();
        for(int b : barcodes) freq.put(b, freq.getOrDefault(b, 0) + 1);
        
        PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<>((a, b) -> b.getValue() - a.getValue());
        pq.addAll(freq.entrySet());
        
        int[] res = new int[n];
        int idx = 0;
        while(!pq.isEmpty()) {
            Map.Entry<Integer, Integer> e = pq.poll();
            int val = e.getKey();
            int count = e.getValue();
            
            for(int i=0; i<count; i++) {
                if(idx >= n) idx = 1;
                res[idx] = val;
                idx += 2;
            }
        }
        
        for(int x : res) System.out.print(x + " ");
    }
}
