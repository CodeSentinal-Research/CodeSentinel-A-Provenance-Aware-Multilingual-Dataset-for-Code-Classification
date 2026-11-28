import java.util.*;

public class Solution {
    private int backtrack(int idx, String[] words, int[] count, int[] score) {
        if (idx == words.length) return 0;
        int maxS = backtrack(idx + 1, words, count, score);

        String w = words[idx];
        int[] wCount = new int[26];
        int wScore = 0;
        boolean canForm = true;

        for (char c : w.toCharArray()) {
            wCount[c - 'a']++;
            wScore += score[c - 'a'];
            if (wCount[c - 'a'] > count[c - 'a']) canForm = false;
        }

        if (canForm) {
            for (int i = 0; i < 26; i++) count[i] -= wCount[i];
            maxS = Math.max(maxS, wScore + backtrack(idx + 1, words, count, score));
            for (int i = 0; i < 26; i++) count[i] += wCount[i];
        }
        return maxS;
    }

    public int maxScoreWords(String[] words, char[] letters, int[] score) {
        int[] count = new int[26];
        for (char c : letters) count[c - 'a']++;
        return backtrack(0, words, count, score);
    }
}