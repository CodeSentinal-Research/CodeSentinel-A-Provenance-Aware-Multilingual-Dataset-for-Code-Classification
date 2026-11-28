import java.util.*;

public class Solution {
    private Map<String, List<String>> memo = new HashMap<>();

    public List<String> wordBreak(String s, List<String> wordDict) {
        if (memo.containsKey(s)) return memo.get(s);
        List<String> res = new ArrayList<>();
        if (s.isEmpty()) {
            res.add("");
            return res;
        }

        for (String w : wordDict) {
            if (s.startsWith(w)) {
                List<String> sub = wordBreak(s.substring(w.length()), wordDict);
                for (String sentence : sub) {
                    res.add(w + (sentence.isEmpty() ? "" : " ") + sentence);
                }
            }
        }
        memo.put(s, res);
        return res;
    }
}