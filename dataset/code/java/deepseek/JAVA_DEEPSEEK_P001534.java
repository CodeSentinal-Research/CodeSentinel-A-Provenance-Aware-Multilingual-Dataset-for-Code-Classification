import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        System.out.println(longestSubstring(input));
    }

    public static int longestSubstring(String s) {
        int n = s.length();
        Map<Character, Integer> map = new HashMap<>();
        int ans = 0, i = 0, j = 0;
        while (i < n) {
            if (map.containsKey(s.charAt(i))) {
                i = map.get(s.charAt(i)) + 1;
                continue;
            }
            map.put(s.charAt(i), i);
            ans = Math.max(ans, i - j);
            i++;
        }
        return ans;
    }
}
