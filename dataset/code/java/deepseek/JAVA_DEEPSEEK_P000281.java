import java.util.HashMap;
import java.util.Map;

public class Main {
    public static void main(String[] args) {
        String S = "ADOBECODEBANC";
        String T = "ABC";
        System.out.println(minWindow(S, T));
    }

    public static String minWindow(String s, String t) {
        if (s == null || s.length() == 0 || t == null || t.length() == 0) {
            return "";
        }

        Map<Character, Integer> map = new HashMap<>();
        for (char c : t.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }

        int left = 0, right = 0, minLen = Integer.MAX_VALUE, counter = map.size();
        String minStr = "";

        while (right < s.length()) {
            char c = s.charAt(right);
            if (map.containsKey(c)) {
                map.put(c, map.get(c) - 1);
                if (map.get(c) == 0) {
                    counter--;
                }
            }
            right++;

            while (counter == 0) {
                if (right - left < minLen) {
                    minLen = right - left;
                    minStr = s.substring(left, right);
                }
                char temp = s.charAt(left);
                if (map.containsKey(temp)) {
                    map.put(temp, map.get(temp) + 1);
                    if (map.get(temp) > 0) {
                        counter++;
                    }
                }
                left++;
            }
        }

        return minStr;
    }
}
