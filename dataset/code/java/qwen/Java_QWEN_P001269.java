import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        
        if(n % k != 0) { System.out.println("NO"); return; }
        
        Map<Integer, Integer> freq = new HashMap<>();
        for(int num : nums) freq.put(num, freq.getOrDefault(num, 0) + 1);
        
        PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<>((a, b) -> b.getValue() - a.getValue());
        pq.addAll(freq.entrySet());
        
        List<List<Integer>> groups = new ArrayList<>();
        for(int i=0; i<n/k; i++) groups.add(new ArrayList<>());
        
        int idx = 0;
        while(!pq.isEmpty()) {
            Map.Entry<Integer, Integer> entry = pq.poll();
            int num = entry.getKey();
            int count = entry.getValue();
            
            for(int i=0; i<count; i++) {
                groups.get(idx % (n/k)).add(num);
                idx++;
            }
        }
        
        for(List<Integer> group : groups) {
            Collections.sort(group);
            for(int i=1; i<group.size(); i++) {
                if(group.get(i) != group.get(i-1) + 1) {
                    System.out.println("NO");
                    return;
                }
            }
        }
        System.out.println("YES");
    }
}
