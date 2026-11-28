import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        Set<String> dictionary = new HashSet<>();
        for (int i = 0; i < n; i++) {
            dictionary.add(scanner.nextLine().trim());
        }
        String s = scanner.nextLine().trim();
        System.out.println(wordBreak(s, dictionary) ? "Yes" : "No");
    }

    public static boolean wordBreak(String s, Set<String> dict) {
        boolean[] f = new boolean[s.length() + 1];
        f[0] = true;
        for (int i = 1; i <= s.length(); i++) {
            for (String word : dict) {
                if (word.length() <= i && f[i - word.length()] && s.startsWith(word, i - word.length())) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[s.length()];
    }
}
