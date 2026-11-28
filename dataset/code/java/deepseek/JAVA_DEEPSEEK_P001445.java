import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String s = scanner.nextLine();
        int n = scanner.nextInt();
        scanner.nextLine();

        Set<String> words = new HashSet<>();
        for (int i = 0; i < n; i++) {
            words.add(scanner.nextLine());
        }

        int count = 0;
        for (String word : words) {
            if (isSubsequence(s, word)) {
                count++;
            }
        }

        System.out.println(count);
    }

    private static boolean isSubsequence(String s, String t) {
        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            if (s.charAt(i) == t.charAt(j)) {
                i++;
            }
            j++;
        }
        return i == s.length();
    }
}
