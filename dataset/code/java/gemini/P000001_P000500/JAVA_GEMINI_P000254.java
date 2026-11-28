public class Solution {
    public int countConsonants(String s) {
        int count = 0;
        String vowels = "aeiouAEIOU";
        for (char c : s.toCharArray()) {
            if (Character.isLetter(c) && vowels.indexOf(c) == -1) count++;
        }
        return count;
    }
}