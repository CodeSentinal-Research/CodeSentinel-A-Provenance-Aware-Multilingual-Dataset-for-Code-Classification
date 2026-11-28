import java.util.*;

public class Main {
    public static void main(String[] args) {
        String[] words = new Scanner(System.in).useDelimiter("\\A").next().split("\\s+");
        System.out.println(String.join(" ", findWords(words)));
    }

    public static List<String> findWords(String[] words) {
        Set<Character> row1 = new HashSet<>(Arrays.asList('q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P'));
        Set<Character> row2 = new HashSet<>(Arrays.asList('a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L'));
        Set<Character> row3 = new HashSet<>(Arrays.asList('z', 'x', 'c', 'v', 'b', 'n', 'm', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'));

        List<String> result = new ArrayList<>();
        for (String word : words) {
            if (isOneRow(word, row1, row2, row3)) {
                result.add(word);
            }
        }
        return result;
    }

    private static boolean isOneRow(String word, Set<Character> row1, Set<Character> row2, Set<Character> row3) {
        for (char c : word.toCharArray()) {
            if (!(row1.contains(c) || row2.contains(c) || row3.contains(c))) {
                return false;
            }
        }
        return true;
    }
}
