import java.util.HashSet;
import java.util.Set;

public class Solution {
    public int countCompleteVowelSubstrings(String word) {
        String vowels = "aeiou";
        int ans = 0, n = word.length();

        for (int i = 0; i < n; i++) {
            Set<Character> seen = new HashSet<>();
            for (int j = i; j < n; j++) {
                char c = word.charAt(j);
                if (vowels.indexOf(c) == -1) break;
                seen.add(c);
                if (seen.size() == 5) ans++;
            }
        }
        return ans;
    }
}