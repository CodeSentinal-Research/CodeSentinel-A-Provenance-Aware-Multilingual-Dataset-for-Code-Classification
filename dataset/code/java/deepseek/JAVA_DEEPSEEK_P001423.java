import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        scanner.nextLine();

        Map<Character, String> charToStr = new HashMap<>();
        Map<String, Character> strToChar = new HashMap<>();

        for (int i = 0; i < n; i++) {
            String word = scanner.nextLine();
            char[] chars = word.toCharArray();
            Arrays.sort(chars);
            String sortedWord = new String(chars);

            if (!charToStr.containsKey(sortedWord.charAt(0))) {
                charToStr.put(sortedWord.charAt(0), sortedWord);
                strToChar.put(sortedWord, sortedWord.charAt(0));
            } else {
                String existingWord = charToStr.get(sortedWord.charAt(0));
                if (word.length() < existingWord.length()) {
                    charToStr.put(sortedWord.charAt(0), sortedWord);
                    strToChar.put(sortedWord, sortedWord.charAt(0));
                }
            }
        }

        String pattern = scanner.nextLine();
        Arrays.sort(pattern.toCharArray());

        for (int i = 0; i < pattern.length(); i++) {
            if (strToChar.containsKey(pattern.substring(0, i + 1))) {
                pattern = pattern.substring(0, i + 1) + strToChar.get(pattern.substring(0, i + 1)) + pattern.substring(i + 1);
            }
        }

        System.out.println(pattern);
    }
}
