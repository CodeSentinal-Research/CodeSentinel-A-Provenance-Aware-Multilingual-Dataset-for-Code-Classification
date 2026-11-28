import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        int k = scanner.nextInt();
        System.out.println(lengthOfLongestSubstring(input, k));
    }

    public static int lengthOfLongestSubstring(String s, int k) {
        int n = s.length();
        int res = 0;
        Map<Character, Integer> map = new HashMap<>();
        int i = 0, j = 0;
        while (i < n && j < n) {
            if (map.size() <= k) {
                map.put(s.charAt(j), j++);
            } else {
                map.remove(s.charAt(i));
                i++;
            }
            res = Math.max(res, j - i);
        }
        return res;
    }
}
