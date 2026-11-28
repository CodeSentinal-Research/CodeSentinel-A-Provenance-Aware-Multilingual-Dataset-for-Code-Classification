import java.util.*;

public class Solution {
    public boolean areSentencesSimilar(String[] sentence1, String[] sentence2, List<List<String>> similarPairs) {
        if (sentence1.length != sentence2.length) return false;
        Set<String> sim = new HashSet<>();
        for (List<String> p : similarPairs) {
            sim.add(p.get(0) + "#" + p.get(1));
            sim.add(p.get(1) + "#" + p.get(0));
        }

        for (int i = 0; i < sentence1.length; i++) {
            String w1 = sentence1[i], w2 = sentence2[i];
            if (!w1.equals(w2) && !sim.contains(w1 + "#" + w2)) {
                return false;
            }
        }
        return true;
    }
}