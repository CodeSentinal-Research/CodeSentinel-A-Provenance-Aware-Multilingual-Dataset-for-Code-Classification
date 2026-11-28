import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next();
        int K = scanner.nextInt();
        System.out.println(characterReplacement(S, K));
    }

    public static int characterReplacement(String s, int k) {
        int[] count = new int[26];
        int start = 0, maxCount = 0, maxLength = 0;
        for(int end = 0; end < s.length(); end++) {
            maxCount = Math.max(maxCount, ++count[s.charAt(end) - 'A']);
            while(end - start + 1 - maxCount > k) {
                count[s.charAt(start) - 'A']--;
                start++;
            }
            maxLength = Math.max(maxLength, end - start + 1);
        }
        return maxLength;
    }
}
