import java.util.*;

public class Solution {
    static class UnionFind {
        Map<String, String> parent = new HashMap<>();

        String find(String s) {
            parent.putIfAbsent(s, s);
            if (!parent.get(s).equals(s)) {
                parent.put(s, find(parent.get(s)));
            }
            return parent.get(s);
        }

        void union(String s1, String s2) {
            String r1 = find(s1), r2 = find(s2);
            if (!r1.equals(r2)) {
                parent.put(r1, r2);
            }
        }
    }

    public boolean areSentencesSimilarTwo(String[] sentence1, String[] sentence2, List<List<String>> similarPairs) {
        if (sentence1.length != sentence2.length) return false;
        UnionFind uf = new UnionFind();
        for (List<String> p : similarPairs) {
            uf.union(p.get(0), p.get(1));
        }

        for (int i = 0; i < sentence1.length; i++) {
            String w1 = sentence1[i], w2 = sentence2[i];
            if (!w1.equals(w2) && !uf.find(w1).equals(uf.find(w2))) {
                return false;
            }
        }
        return true;
    }
}