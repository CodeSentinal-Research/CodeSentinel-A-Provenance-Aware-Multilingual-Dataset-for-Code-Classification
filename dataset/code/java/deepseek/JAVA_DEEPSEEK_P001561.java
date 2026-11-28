import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.nextLine();
        int M = scanner.nextInt();
        String[] words = new String[M];
        for (int i = 0; i < M; i++) {
            words[i] = scanner.nextLine();
        }
        List<Integer> result = findSubstring(S, words);
        if (result.isEmpty()) {
            System.out.println(-1);
        } else {
            for (int i : result) {
                System.out.println(i);
            }
        }
    }

    public static List<Integer> findSubstring(String s, String[] words) {
        List<Integer> result = new ArrayList<>();
        if (s == null || s.length() == 0 || words == null || words.length == 0) {
            return result;
        }

        int wordBits = 0;
        for (String word : words) {
            wordBits += word.length();
        }

        int wordCount = words.length;
        int wordLength = words[0].length();

        for (int i = 0; i <= s.length() - wordBits; i++) {
            int j = i;
            int k = 0;
            for (k = 0; k < wordCount; k++) {
                int index = s.substring(j, j + wordLength).equals(words[k]) ? j : -1;
                if (index == -1) {
                    break;
                }
                j += wordLength;
            }
            if (k == wordCount) {
                result.add(i);
            }
        }
        return result;
    }
}
