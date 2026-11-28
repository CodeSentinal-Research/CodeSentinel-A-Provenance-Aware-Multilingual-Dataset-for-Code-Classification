import java.util.*;

public class Solution {
    private static boolean isSubsequence(String sub, String s) {
        int i = 0;
        for (int j = 0; j < s.length() && i < sub.length(); j++) {
            if (s.charAt(j) == sub.charAt(i)) i++;
        }
        return i == sub.length();
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            List<String> words = new ArrayList<>();
            while (scanner.hasNext()) words.add(scanner.next());
            words.sort((a, b) -> {
                if (a.length() != b.length()) return Integer.compare(b.length(), a.length());
                return a.compareTo(b);
            });
            for (String word : words) {
                if (isSubsequence(word, s)) {
                    System.out.println(word);
                    return;
                }
            }
            System.out.println("");
        }
    }
}