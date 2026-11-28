import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int capacity = sc.nextInt();
        int q = sc.nextInt();
        LFUCache cache = new LFUCache(capacity);
        for(int i=0; i<q; i++) {
            String op = sc.next();
            if(op.equals("put")) {
                int key = sc.nextInt();
                int val = sc.nextInt();
                cache.put(key, val);
            } else if(op.equals("get")) {
                int key = sc.nextInt();
                System.out.println(cache.get(key));
            }
        }
    }
}
class LFUCache {
    private Map<Integer, Integer> vals;
    private Map<Integer, Integer> counts;
    private Map<Integer, LinkedHashSet<Integer>> lists;
    private int cap;
    private int min;
    
    public LFUCache(int capacity) {
        cap = capacity;
        vals = new HashMap<>();
        counts = new HashMap<>();
        lists = new HashMap<>();
        lists.put(1, new LinkedHashSet<>());
        min = 1;
    }
    
    public int get(int key) {
        if(!vals.containsKey(key)) return -1;
        int count = counts.get(key);
        counts.put(key, count + 1);
        lists.get(count).remove(key);
        if(lists.get(count).size() == 0 && min == count) min++;
        lists.computeIfAbsent(count + 1, k -> new LinkedHashSet<>()).add(key);
        return vals.get(key);
    }
    
    public void put(int key, int value) {
        if(cap == 0) return;
        if(vals.containsKey(key)) {
            vals.put(key, value);
            get(key);
            return;
        }
        if(vals.size() == cap) {
            int evict = lists.get(min).iterator().next();
            lists.get(min).remove(evict);
            vals.remove(evict);
            counts.remove(evict);
        }
        vals.put(key, value);
        counts.put(key, 1);
        min = 1;
        lists.get(1).add(key);
    }
}
