import java.util.List;

public class Main {
    public static void main(String[] args) {
        // Test input
        List<String> words = List.of("fl", "y", "ants", "a");
        String S = "ant";

        System.out.println(countPrefixes(words, S));
    }

    public static int countPrefixes(List<String> words, String S) {
        int count = 0;
        for (String word : words) {
            if (S.startsWith(word)) {
                count++;
            }
        }
        return count;
    }
}
