// package removed

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * LeetCode 30: Substring with Concatenation of All Words
 * You are given a string s and an array of strings words. All strings of words are of the same length.
 * Return all starting indices of substring(s) in s that is a concatenation of each word in words exactly once,
 * without any intervening characters.
 */
public class SubstringConcatenationWords {

    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> result = new ArrayList<>();
        
        if (s == null || words == null || words.length == 0) {
            return result;
        }
        
        int wordLength = words[0].length();
        int totalWords = words.length;
        int totalLength = wordLength * totalWords;
        
        if (s.length() < totalLength) {
            return result;
        }
        
        // Build word frequency map
        Map<String, Integer> wordCount = new HashMap<>();
        for (String word : words) {
            wordCount.put(word, wordCount.getOrDefault(word, 0) + 1);
        }
        
        // Try all possible starting positions
        for (int i = 0; i <= s.length() - totalLength; i++) {
            String substring = s.substring(i, i + totalLength);
            Map<String, Integer> seen = new HashMap<>();
            boolean valid = true;
            
            // Check each word in the substring
            for (int j = 0; j < totalWords; j++) {
                int start = j * wordLength;
                String word = substring.substring(start, start + wordLength);
                
                if (!wordCount.containsKey(word)) {
                    valid = false;
                    break;
                }
                
                seen.put(word, seen.getOrDefault(word, 0) + 1);
                if (seen.get(word) > wordCount.get(word)) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                result.add(i);
            }
        }
        
        return result;
    }

    public static void main(String[] args) {
        SubstringConcatenationWords solution = new SubstringConcatenationWords();
        
        // Test cases
        System.out.println("Indices for s='barfoothefoobarman', words=['foo','bar']: " + 
            solution.findSubstring("barfoothefoobarman", new String[]{"foo", "bar"})); // [0, 9]
        System.out.println("Indices for s='wordgoodgoodgoodbestword', words=['word','good','best','word']: " + 
            solution.findSubstring("wordgoodgoodgoodbestword", new String[]{"word", "good", "best", "word"})); // []
        System.out.println("Indices for s='barfoofoobarthefoobarman', words=['bar','foo','the']: " + 
            solution.findSubstring("barfoofoobarthefoobarman", new String[]{"bar", "foo", "the"})); // [6, 9, 12]
    }
}
