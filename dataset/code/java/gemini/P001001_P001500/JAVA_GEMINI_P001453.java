public class Solution {
    // Calculates modular exponentiation (base^exp % mod) efficiently.
    public int maxPower(String s) {
        int maxRun = 1, curRun = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == s.charAt(i - 1)) {
                curRun++;
                maxRun = Math.max(maxRun, curRun);
            } else {
                curRun = 1;
            }
        }
        return maxRun;
    }
}