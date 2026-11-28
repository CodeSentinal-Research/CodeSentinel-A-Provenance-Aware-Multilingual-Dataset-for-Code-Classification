import java.util.*;

public class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> res = new ArrayList<>();
        if (s.length() == 0 || words.length == 0) return res;

        int wordLen = words[0].length();
        int numWords = words.length;
        Map<String, Integer> wordCount = new HashMap<>();
        for (String w : words) wordCount.put(w, wordCount.getOrDefault(w, 0) + 1);

        for (int i = 0; i < wordLen; i++) {
            int left = i, count = 0;
            Map<String, Integer> curCount = new HashMap<>();

            for (int j = i; j <= s.length() - wordLen; j += wordLen) {
                String w = s.substring(j, j + wordLen);
                if (wordCount.containsKey(w)) {
                    curCount.put(w, curCount.getOrDefault(w, 0) + 1);
                    count++;

                    while (curCount.get(w) > wordCount.get(w)) {
                        String leftW = s.substring(left, left + wordLen);
                        curCount.put(leftW, curCount.get(leftW) - 1);
                        count--;
                        left += wordLen;
                    }

                    if (count == numWords) res.add(left);
                } else {
                    curCount.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }
        return res;
    }
}