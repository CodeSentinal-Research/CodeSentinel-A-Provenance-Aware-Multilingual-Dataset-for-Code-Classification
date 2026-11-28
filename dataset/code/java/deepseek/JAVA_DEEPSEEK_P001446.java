import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String sentence1 = scanner.nextLine();
        String sentence2 = scanner.nextLine();
        int P = scanner.nextInt();
        scanner.nextLine(); // consume the newline character

        Map<String, String> similarWords = new HashMap<>();
        for (int i = 0; i < P; i++) {
            String[] pair = scanner.nextLine().split(" ");
            similarWords.put(pair[0], pair[1]);
        }

        System.out.println(areSentencesSimilar(sentence1, sentence2, similarWords) ? "YES" : "NO");
    }

    private static boolean areSentencesSimilar(String sentence1, String sentence2, Map<String, String> similarWords) {
        String[] sentence1Words = sentence1.split(" ");
        String[] sentence2Words = sentence2.split(" ");

        if (sentence1Words.length != sentence2Words.length) {
            return false;
        }

        for (int i = 0; i < sentence1Words.length; i++) {
            if (!sentence1Words[i].equals(sentence2Words[i])) {
                if (!similarWords.containsKey(sentence1Words[i]) || !similarWords.get(sentence1Words[i]).equals(sentence2Words[i])) {
                    return false;
                }
            }
        }

        return true;
    }
}
