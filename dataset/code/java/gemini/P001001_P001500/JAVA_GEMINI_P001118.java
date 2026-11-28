import java.util.*;

public class Solution {
    public String alienOrder(String[] words) {
        Map<Character, Set<Character>> adj = new HashMap<>();
        Map<Character, Integer> inDeg = new HashMap<>();
        for (String w : words) {
            for (char c : w.toCharArray()) {
                inDeg.put(c, 0);
                adj.putIfAbsent(c, new HashSet<>());
            }
        }

        for (int i = 0; i < words.length - 1; i++) {
            String w1 = words[i], w2 = words[i + 1];
            int minLen = Math.min(w1.length(), w2.length());
            if (w1.length() > w2.length() && w1.startsWith(w2)) return "";
            for (int j = 0; j < minLen; j++) {
                char c1 = w1.charAt(j), c2 = w2.charAt(j);
                if (c1 != c2) {
                    if (!adj.get(c1).contains(c2)) {
                        adj.get(c1).add(c2);
                        inDeg.put(c2, inDeg.get(c2) + 1);
                    }
                    break;
                }
            }
        }

        Queue<Character> q = new LinkedList<>();
        for (char c : inDeg.keySet()) {
            if (inDeg.get(c) == 0) q.offer(c);
        }

        StringBuilder sb = new StringBuilder();
        while (!q.isEmpty()) {
            char c = q.poll();
            sb.append(c);
            for (char nxt : adj.get(c)) {
                inDeg.put(nxt, inDeg.get(nxt) - 1);
                if (inDeg.get(nxt) == 0) q.offer(nxt);
            }
        }

        return sb.length() == inDeg.size() ? sb.toString() : "";
    }
}