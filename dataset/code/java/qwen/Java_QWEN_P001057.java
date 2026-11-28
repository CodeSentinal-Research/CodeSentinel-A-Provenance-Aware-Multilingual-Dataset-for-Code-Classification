import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] arr = new int[n];
        Map<Integer, Integer> freq = new HashMap<>();
        for(int i=0; i<n; i++) {
            arr[i] = sc.nextInt();
            freq.put(arr[i], freq.getOrDefault(arr[i], 0) + 1);
        }
        
        PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<>((a, b) -> a.getValue() - b.getValue());
        for(Map.Entry<Integer, Integer> e : freq.entrySet()) pq.offer(e);
        
        while(k > 0 && !pq.isEmpty()) {
            Map.Entry<Integer, Integer> e = pq.poll();
            if(e.getValue() <= k) {
                k -= e.getValue();
            } else {
                break;
            }
        }
        
        System.out.println(pq.size());
    }
}
