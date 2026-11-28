import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.next();
        int n = scanner.nextInt();
        scanner.nextLine();
        List<String> words = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            words.add(scanner.nextLine());
        }
        System.out.println(findLongestWord(S, words));
    }

    public static String findLongestWord(String S, List<String> words) {
        String res = "";
        for (String word : words) {
            if (isSubsequence(S, word) && word.length() > res.length()) {
                res = word;
            } else if (word.length() == res.length() && word.compareTo(res) < 0) {
                res = word;
            }
        }
        return res;
    }

    public static boolean isSubsequence(String S, String word) {
        int i = 0, j = 0;
        while (i < S.length() && j < word.length()) {
            if (S.charAt(i) == word.charAt(j)) {
                j++;
            }
            i++;
        }
        return j == word.length();
    }
}
