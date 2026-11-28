import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        String[] words = new String[n];
        for (int i = 0; i < n; i++) {
            words[i] = scanner.nextLine();
        }
        String order = scanner.nextLine();
        System.out.println(isAlienSorted(words, order) ? "YES" : "NO");
    }

    public static boolean isAlienSorted(String[] words, String order) {
        Map<Character, Integer> charToIndex = new HashMap<>();
        for (int i = 0; i < order.length(); i++) {
            charToIndex.put(order.charAt(i), i);
        }
        for (int i = 0; i < words.length - 1; i++) {
            String word1 = words[i];
            String word2 = words[i + 1];
            int j = 0, k = 0;
            while (j < word1.length() && k < word2.length()) {
                if (charToIndex.get(word1.charAt(j)) < charToIndex.get(word2.charAt(k))) {
                    return false;
                } else if (charToIndex.get(word1.charAt(j)) > charToIndex.get(word2.charAt(k))) {
                    break;
                } else {
                    j++;
                    k++;
                }
            }
            if (j < word1.length() && k >= word2.length()) {
                return false;
            }
        }
        return true;
    }
}
