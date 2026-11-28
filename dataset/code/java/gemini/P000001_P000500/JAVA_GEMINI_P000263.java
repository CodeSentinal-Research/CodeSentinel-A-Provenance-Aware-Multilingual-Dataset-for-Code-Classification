public class Solution {
    public char lastNonRepeatingCharacter(String s) {
        int[] freq = new int[256];
        for (char c : s.toCharArray()) freq[c]++;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (freq[s.charAt(i)] == 1) return s.charAt(i);
        }
        return '$';
    }
}