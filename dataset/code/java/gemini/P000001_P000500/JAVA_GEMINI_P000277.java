import java.util.*;
public class Solution {
    public static void main(String[] args) {
        // Initialize scanner for standard input
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            Set<Character> set = new HashSet<>();
            int left = 0, maxLen = 0;
            // Expand window to the right
            for (int right = 0; right < s.length(); right++) {
                // Shrink window from the left while duplicate exists
                while (set.contains(s.charAt(right))) {
                    set.remove(s.charAt(left++));
                }
                set.add(s.charAt(right));
                maxLen = Math.max(maxLen, right - left + 1);
            }
            System.out.println(maxLen);
        }
    }
}