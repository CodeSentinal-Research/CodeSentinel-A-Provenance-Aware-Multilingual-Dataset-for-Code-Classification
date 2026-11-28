import java.util.*;

public class Solution {
    private Map<String, PriorityQueue<String>> map = new HashMap<>();
    private List<String> res = new LinkedList<>();

    private void dfs(String curr) {
        PriorityQueue<String> pq = map.get(curr);
        while (pq != null && !pq.isEmpty()) {
            dfs(pq.poll());
        }
        res.add(0, curr);
    }

    public List<String> findItinerary(List<List<String>> tickets) {
        for (List<String> t : tickets) {
            map.computeIfAbsent(t.get(0), k -> new PriorityQueue<>()).offer(t.get(1));
        }
        dfs("JFK");
        return res;
    }
}