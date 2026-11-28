public class Solution {
    public boolean validAnagramAfterRemoval(String s, String t) {
        if (s.length() != t.length() + 1) return false;
        int[] freqS = new int[256];
        int[] freqT = new int[256];

        for (char c : s.toCharArray()) freqS[c]++;
        for (char c : t.toCharArray()) freqT[c]++;

        int diff = 0;
        for (int i = 0; i < 256; i++) {
            if (freqS[i] > freqT[i]) diff += freqS[i] - freqT[i];
            else if (freqS[i] < freqT[i]) return false;
        }
        return diff == 1;
    }
}