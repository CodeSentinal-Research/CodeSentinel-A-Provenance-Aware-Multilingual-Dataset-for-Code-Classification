import java.util.HashSet;
import java.util.Set;

public class Solution {
    public String removeDuplicates(String s) {
        Set<Character> seen = new HashSet<>();
        StringBuilder sb = new StringBuilder();
        for (char c : s.toCharArray()) {
            if (seen.add(c)) sb.append(c);
        }
        return sb.toString();
    }
}