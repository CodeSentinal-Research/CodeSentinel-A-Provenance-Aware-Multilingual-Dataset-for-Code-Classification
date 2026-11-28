import java.util.*;

public class Solution {
    private static void backtrack(String s, int index, List<String> parts, List<String> res) {
        if (parts.size() == 4) {
            if (index == s.length()) {
                res.add(String.join(".", parts));
            }
            return;
        }
        for (int len = 1; len <= 3 && index + len <= s.length(); len++) {
            String segment = s.substring(index, index + len);
            if (segment.length() > 1 && segment.charAt(0) == '0') continue;
            int val = Integer.parseInt(segment);
            if (val > 255) continue;
            parts.add(segment);
            backtrack(s, index + len, parts, res);
            parts.remove(parts.size() - 1);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            List<String> parts = new ArrayList<>();
            List<String> res = new ArrayList<>();
            backtrack(s, 0, parts, res);
            for (String ip : res) {
                System.out.println(ip);
            }
        }
    }
}