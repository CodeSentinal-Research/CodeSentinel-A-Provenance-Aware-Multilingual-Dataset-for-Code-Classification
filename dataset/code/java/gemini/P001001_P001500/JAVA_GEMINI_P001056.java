import java.util.HashSet;
import java.util.PriorityQueue;
import java.util.Set;

public class SmallestInfiniteSet {
    private int cur;
    private Set<Integer> added;
    private PriorityQueue<Integer> pq;

    public SmallestInfiniteSet() {
        cur = 1;
        added = new HashSet<>();
        pq = new PriorityQueue<>();
    }

    public int popSmallest() {
        if (!pq.isEmpty()) {
            int val = pq.poll();
            added.remove(val);
            return val;
        }
        return cur++;
    }

    public void addBack(int num) {
        if (num < cur && added.add(num)) {
            pq.offer(num);
        }
    }
}