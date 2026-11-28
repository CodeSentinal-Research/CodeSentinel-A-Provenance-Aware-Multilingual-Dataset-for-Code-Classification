public class Solution {
    public boolean isDuck(String s) {
        int i = 0;
        while (i < s.length() && s.charAt(i) == '0') i++;
        while (i < s.length()) {
            if (s.charAt(i) == '0') return true;
            i++;
        }
        return false;
    }
}
