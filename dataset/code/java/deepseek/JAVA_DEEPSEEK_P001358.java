import java.util.*;

public class Main {
    static List<String> abbreviations = new ArrayList<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String word = scanner.nextLine();
        backtrack("", word, 0, 0);
        Collections.sort(abbreviations);
        for (String s : abbreviations) {
            System.out.println(s);
        }
    }

    private static void backtrack(String curr, String word, int index, int count) {
        if (index == word.length()) {
            if (count > 0) {
                curr += count;
            }
            abbreviations.add(curr);
            return;
        }
        backtrack(curr, word, index + 1, count + 1);
        backtrack(curr + word.charAt(index), word, index + 1, 0);
    }
}
