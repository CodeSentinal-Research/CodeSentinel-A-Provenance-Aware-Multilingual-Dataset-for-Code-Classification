import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String pattern = scanner.nextLine();
        String sentence = scanner.nextLine();

        Map<Character, Character> patternMap = new HashMap<>();
        Map<Character, Character> sentenceMap = new HashMap<>();

        for (int i = 0; i < pattern.length(); i++) {
            if (i % 2 == 0) {
                patternMap.put(pattern.charAt(i), pattern.charAt(i + 1));
            } else {
                sentenceMap.put(sentence.charAt(i), sentence.charAt(i + 1));
            }
        }

        for (int i = 0; i < sentence.length(); i++) {
            if (i % 2 == 0) {
                if (!patternMap.containsKey(sentence.charAt(i))) {
                    System.out.println("NO");
                    return;
                }
                if (sentenceMap.containsKey(sentence.charAt(i))) {
                    if (sentenceMap.get(sentence.charAt(i)) != patternMap.get(sentence.charAt(i))) {
                        System.out.println("NO");
                        return;
                    }
                } else {
                    System.out.println("NO");
                    return;
                }
            }
        }

        System.out.println("YES");
    }
}
