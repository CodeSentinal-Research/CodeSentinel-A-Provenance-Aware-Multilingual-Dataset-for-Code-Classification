import java.util.*;

public class Main {
    static int maxScore = 0;
    static int[] scores;
    static String[] words;
    static boolean[] used;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        words = new String[n];
        for (int i = 0; i < n; i++) {
            words[i] = scanner.nextLine();
        }
        String letters = scanner.nextLine();
        scores = new int[26];
        for (int i = 0; i < 26; i++) {
            scores[i] = scanner.nextInt();
        }
        used = new boolean[26];
        backtrack(letters, 0);
        System.out.println(maxScore);
    }

    private static void backtrack(String letters, int start) {
        if (start == letters.length()) {
            maxScore = Math.max(maxScore, scoreWords());
            return;
        }
        used[letters.charAt(start) - 'a'] = true;
        backtrack(letters, start + 1);
        used[letters.charAt(start) - 'a'] = false;
        backtrack(letters, start + 1);
    }

    private static int scoreWords() {
        int score = 0;
        for (String word : words) {
            int wordScore = 0;
            for (char c : word.toCharArray()) {
                wordScore += scores[c - 'a'];
            }
            score = Math.max(score, wordScore);
        }
        return score;
    }
}
