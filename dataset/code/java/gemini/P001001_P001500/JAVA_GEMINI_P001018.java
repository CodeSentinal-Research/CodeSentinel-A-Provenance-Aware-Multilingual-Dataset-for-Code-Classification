import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

public class Solution {
    public String reorganizeString(String s) {
        Map<Character, Integer> counts = new HashMap<>();
        for (char c : s.toCharArray()) counts.put(c, counts.getOrDefault(c, 0) + 1);

        PriorityQueue<Character> pq = new PriorityQueue<>((a, b) -> counts.get(b) - counts.get(a));
        pq.addAll(counts.keySet());

        if (counts.get(pq.peek()) > (s.length() + 1) / 2) return "";

        StringBuilder sb = new StringBuilder();
        while (pq.size() >= 2) {
            char c1 = pq.poll();
            char c2 = pq.poll();
            sb.append(c1).append(c2);
            counts.put(c1, counts.get(c1) - 1);
            counts.put(c2, counts.get(c2) - 1);
            if (counts.get(c1) > 0) pq.offer(c1);
            if (counts.get(c2) > 0) pq.offer(c2);
        }
        if (!pq.isEmpty()) sb.append(pq.poll());
        return sb.toString();
    }
}