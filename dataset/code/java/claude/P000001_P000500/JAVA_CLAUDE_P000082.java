public class Solution {
    public boolean isSpecial(char c) {
        return !Character.isLetterOrDigit(c) && !Character.isWhitespace(c);
    }
}
