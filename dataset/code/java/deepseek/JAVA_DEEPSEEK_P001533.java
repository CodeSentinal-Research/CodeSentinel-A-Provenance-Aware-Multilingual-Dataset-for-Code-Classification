import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        int k = scanner.nextInt();
        System.out.println(longestSubstring(input, k));
    }

    public static int longestSubstring(String s, int k) {
        int n = s.length();
        Map<Character, Integer> map = new HashMap<>();
        int maxLen = 0;
        int distinctCount = 0;
        int start = 0;

        for (int end = 0; end < n; end++) {
            char c = s.charAt(end);
            if (map.containsKey(c)) {
                map.put(c, map.get(c) + 1);
            } else {
                map.put(c, 1);
            }

            if (map.size() == k) {
                distinctCount = end - start + 1;
                maxLen = Math.max(maxLen, distinctCount);
                while (map.get(s.charAt(start)) > 1) {
                    map.put(s.charAt(start), map.get(s.charAt(start)) - 1);
                    start++;
                }
                map.remove(s.charAt(start));
                start++;
            }
        }

        return maxLen;
    }
}
