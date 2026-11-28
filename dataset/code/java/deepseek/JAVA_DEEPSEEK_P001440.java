import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String source = scanner.nextLine();
        int n = scanner.nextInt();
        scanner.nextLine();
        Set<String> dictionary = new HashSet<>();
        for (int i = 0; i < n; i++) {
            dictionary.add(scanner.nextLine());
        }
        String longestWord = "";
        for (String word : dictionary) {
            if (canForm(source, word)) {
                longestWord = word;
                break;
            }
        }
        System.out.println(longestWord.isEmpty() ? "None" : longestWord);
    }

    private static boolean canForm(String source, String word) {
        int i = 0, j = 0;
        while (i < source.length() && j < word.length()) {
            if (source.charAt(i) == word.charAt(j)) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        return j == word.length();
    }
}
