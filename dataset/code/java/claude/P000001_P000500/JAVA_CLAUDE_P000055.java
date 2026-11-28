public class Solution {
    public String printAlphabetZA() {
        StringBuilder sb = new StringBuilder();
        for (char c = 'Z'; c >= 'A'; c--) {
            sb.append(c);
        }
        return sb.toString();
    }
}
