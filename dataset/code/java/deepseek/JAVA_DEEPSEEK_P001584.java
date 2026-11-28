import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        int k = scanner.nextInt();
        System.out.println(longestSubstring(s, k));
    }

    public static int longestSubstring(String s, int k) {
        int left = 0, right = 0, vowels = 0, max = 0;
        int[] count = new int[26];

        while (right < s.length()) {
            if (isVowel(s.charAt(right))) {
                vowels++;
            }
            count[s.charAt(right) - 'a']++;
            right++;

            while (vowels > k) {
                if (isVowel(s.charAt(left))) {
                    vowels--;
                }
                count[s.charAt(left) - 'a']--;
                left++;
            }

            max = Math.max(max, right - left + 1);
        }

        return max;
    }

    public static boolean isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}
