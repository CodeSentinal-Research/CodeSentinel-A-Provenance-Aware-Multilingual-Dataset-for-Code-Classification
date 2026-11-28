public class Solution {
    public String removeConsonants(String s) {
        StringBuilder sb = new StringBuilder();
        String vowels = "aeiouAEIOU";
        for (char c : s.toCharArray()) {
            if (!Character.isLetter(c) || vowels.indexOf(c) != -1) sb.append(c);
        }
        return sb.toString();
    }
}