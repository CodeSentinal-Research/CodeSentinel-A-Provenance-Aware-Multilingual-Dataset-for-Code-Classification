public class Solution {
    public int compress(char[] chars) {
        int write = 0, read = 0, n = chars.length;

        while (read < n) {
            char ch = chars[read];
            int count = 0;
            while (read < n && chars[read] == ch) {
                read++;
                count++;
            }

            chars[write++] = ch;

            if (count > 1) {
                for (char c : Integer.toString(count).toCharArray()) {
                    chars[write++] = c;
                }
            }
        }
        return write;
    }
}