import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        List<String> words = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            words.add(scanner.nextLine());
        }

        Set<String> result = new HashSet<>();
        for (String word : words) {
            if (isValid(word)) {
                result.add(word);
            }
        }

        List<String> sortedWords = new ArrayList<>(result);
        Collections.sort(sortedWords);

        for (String word : sortedWords) {
            System.out.println(word);
        }
    }

    private static boolean isValid(String word) {
        Set<Character> row1 = new HashSet<>();
        for (char c : "qwertyuiopQWERTYUIOP".toCharArray()) {
            row1.add(c);
        }

        Set<Character> row2 = new HashSet<>();
        for (char c : "asdfghjklASDFGHJKL".toCharArray()) {
            row2.add(c);
        }

        Set<Character> row3 = new HashSet<>();
        for (char c : "zxcvbnmZXCVBNM".toCharArray()) {
            row3.add(c);
        }

        for (char c : word.toCharArray()) {
            if (row1.contains(c) || row2.contains(c) || row3.contains(c)) {
                return true;
            }
        }

        return false;
    }
}
