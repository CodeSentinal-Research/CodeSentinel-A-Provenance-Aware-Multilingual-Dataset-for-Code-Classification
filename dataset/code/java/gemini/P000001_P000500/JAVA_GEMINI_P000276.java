public class Solution {
    public String countAndSay(int n) {
        String s = "1";
        for (int step = 1; step < n; step++) {
            StringBuilder sb = new StringBuilder();
            int i = 0;
            while (i < s.length()) {
                int count = 1;
                while (i + 1 < s.length() && s.charAt(i) == s.charAt(i + 1)) {
                    i++;
                    count++;
                }
                sb.append(count).append(s.charAt(i));
                i++;
            }
            s = sb.toString();
        }
        return s;
    }
}