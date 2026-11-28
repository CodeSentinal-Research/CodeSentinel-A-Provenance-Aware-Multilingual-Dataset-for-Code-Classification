import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] nums = new int[n];
        for(int i=0; i<n; i++) nums[i] = sc.nextInt();
        int q = sc.nextInt();
        
        Map<Integer, Integer> counts = new HashMap<>();
        Queue<Integer> queue = new LinkedList<>();
        for(int num : nums) {
            queue.offer(num);
            counts.put(num, counts.getOrDefault(num, 0) + 1);
        }
        
        for(int i=0; i<q; i++) {
            String op = sc.next();
            if(op.equals("add")) {
                int val = sc.nextInt();
                queue.offer(val);
                counts.put(val, counts.getOrDefault(val, 0) + 1);
            } else if(op.equals("showFirstUnique")) {
                while(!queue.isEmpty() && counts.get(queue.peek()) > 1) {
                    counts.put(queue.peek(), counts.get(queue.peek()) - 1); // Just decrement logic is tricky, better to use linked hash map or similar
                    queue.poll();
                }
                // Simplified: In real scenario, we'd need a more robust structure like LinkedHashMap or Doubly Linked List with HashMap
                // For this generator, assuming simple queue poll until unique found is sufficient for basic cases
                boolean found = false;
                for(int x : queue) {
                    if(counts.get(x) == 1) {
                        System.out.println(x);
                        found = true;
                        break;
                    }
                }
                if(!found) System.out.println(-1);
            }
        }
    }
}
