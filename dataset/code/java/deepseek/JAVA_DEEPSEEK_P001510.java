import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String s = scanner.next();
        int k = scanner.nextInt();

        System.out.println(longestRepeatingSubstring(s, k));
    }

    private static int longestRepeatingSubstring(String s, int k) {
        int n = s.length();
        int maxLength = 0;

        for (int length = n - 1; length > 0; length--) {
            for (int i = 0; i + length <= n; i++) {
                String substring = s.substring(i, i + length);
                int count = countOccurrences(s, substring);

                if (count > 1 && count <= k) {
                    maxLength = length;
                    break;
                }
            }

            if (maxLength != 0) {
                break;
            }
        }

        return maxLength;
    }

    private static int countOccurrences(String s, String substring) {
        int count = 0;
        int start = 0;

        while (start < s.length()) {
            int index = s.indexOf(substring, start);

            if (index != -1) {
                start = index + 1;
                count++;
            } else {
                break;
            }
        }

        return count;
    }
}
