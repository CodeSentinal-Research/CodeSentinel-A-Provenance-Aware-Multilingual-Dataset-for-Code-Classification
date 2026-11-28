import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        int k = scanner.nextInt();
        System.out.println(longestSubstring(s, k));
    }

    public static int longestSubstring(String s, int k) {
        int n = s.length();
        int[] count = new int[26];
        int left = 0, right = 0;
        int maxLen = 0;
        int maxCount = 0;

        while (right < n) {
            count[s.charAt(right) - 'a']++;
            if (count[s.charAt(right) - 'a'] == 1) {
                maxCount++;
            }
            right++;

            while (maxCount == k) {
                count[s.charAt(left) - 'a']--;
                if (count[s.charAt(left) - 'a'] == 0) {
                    maxCount--;
                }
                left++;
            }

            if (maxCount == k) {
                maxLen = Math.max(maxLen, right - left + 1);
            }
        }

        return maxLen;
    }
}
