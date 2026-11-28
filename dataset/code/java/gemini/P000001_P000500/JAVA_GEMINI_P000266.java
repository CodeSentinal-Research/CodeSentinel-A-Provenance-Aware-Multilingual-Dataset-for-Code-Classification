public class Solution {
    public String removeOccurrences(String s, char c) {
        StringBuilder sb = new StringBuilder();
        for (char ch : s.toCharArray()) {
            if (ch != c) sb.append(ch);
        }
        return sb.toString();
    }
}