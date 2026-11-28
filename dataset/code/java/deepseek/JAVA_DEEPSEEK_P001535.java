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
        int[] count = new int[26];
        int max = 0;
        int left = 0;
        int right = 0;
        int maxCount = 0;

        while (right < n) {
            max = Math.max(max, ++count[s.charAt(right++) - 'A']);
            if (max == k) {
                maxCount = Math.max(maxCount, right - left);
            }
            if (max == k) {
                max = count[s.charAt(left++) - 'A'];
                for (int i = 0; i < 26; i++) {
                    count[i] -= max;
                }
                max = maxCount = 0;
            }
        }

        return maxCount;
    }
}
