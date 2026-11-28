import java.util.*;
public class Solution {
    static void restoreIp(String s, int idx, List<String> parts) {
        if (parts.size() == 4) {
            if (idx == s.length()) {
                System.out.println(String.join(".", parts));
            }
            return;
        }
        for (int l = 1; l <= 3 && idx + l <= s.length(); l++) {
            String part = s.substring(idx, idx + l);
            if ((part.charAt(0) == '0' && part.length() > 1) || Integer.parseInt(part) > 255) continue;
            parts.add(part);
            restoreIp(s, idx + l, parts);
            parts.remove(parts.size() - 1);
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            restoreIp(scanner.next(), 0, new ArrayList<>());
        }
    }
}