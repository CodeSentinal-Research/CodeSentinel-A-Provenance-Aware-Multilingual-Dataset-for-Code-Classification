import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        int k = scanner.nextInt();
        System.out.println(lengthOfLongestSubstring(s, k));
    }

    public static int lengthOfLongestSubstring(String s, int k) {
        int n = s.length();
        int res = 0;
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0, j = 0; j < n; j++) {
            char c = s.charAt(j);
            if (map.containsKey(c)) {
                i = Math.max(i, map.get(c));
            }
            map.put(c, j + 1);
            res = Math.max(res, j - i + 1);
        }
        return res;
    }
}
