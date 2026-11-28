public class Solution {
    public int maxVowels(String s, int k) {
        String vowels = "aeiou";
        int curVowels = 0;
        for (int i = 0; i < k; i++) {
            if (vowels.indexOf(s.charAt(i)) != -1) curVowels++;
        }
        int maxVowels = curVowels;

        for (int i = k; i < s.length(); i++) {
            if (vowels.indexOf(s.charAt(i)) != -1) curVowels++;
            if (vowels.indexOf(s.charAt(i - k)) != -1) curVowels--;
            maxVowels = Math.max(maxVowels, curVowels);
        }
        return maxVowels;
    }
}