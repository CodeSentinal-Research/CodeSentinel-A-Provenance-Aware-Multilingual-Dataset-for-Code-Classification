public class Solution {
    public String printAlphabetAZ() {
        StringBuilder sb = new StringBuilder();
        for (char c = 'A'; c <= 'Z'; c++) {
            sb.append(c);
        }
        return sb.toString();
    }
}
