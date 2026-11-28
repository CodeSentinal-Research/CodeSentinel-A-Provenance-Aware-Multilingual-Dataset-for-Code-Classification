import java.util.*;

public class Solution {
    public String[] uncommonFromSentences(String s1, String s2) {
        Map<String, Integer> count = new HashMap<>();
        for (String w : (s1 + " " + s2).split(" ")) {
            count.put(w, count.getOrDefault(w, 0) + 1);
        }

        List<String> list = new ArrayList<>();
        for (String w : count.keySet()) {
            if (count.get(w) == 1) list.add(w);
        }
        return list.toArray(new String[0]);
    }
}