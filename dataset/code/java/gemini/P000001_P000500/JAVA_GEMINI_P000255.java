public class Solution {
    public String removeVowels(String s) {
        StringBuilder sb = new StringBuilder();
        String vowels = "aeiouAEIOU";
        for (char c : s.toCharArray()) {
            if (vowels.indexOf(c) == -1) sb.append(c);
        }
        return sb.toString();
    }
}