import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String S = scanner.nextLine();
        String[] words = scanner.nextLine().split(" ");
        Set<String> dictionary = new HashSet<>(Arrays.asList(words));
        StringBuilder result = new StringBuilder();
        StringBuilder word = new StringBuilder();
        for (int i = 0; i < S.length(); i++) {
            word.append(S.charAt(i));
            if (dictionary.contains(word.toString())) {
                result.append("<b>").append(word).append("</b>");
                word = new StringBuilder();
            } else {
                result.append(S.charAt(i));
            }
        }
        System.out.println(result.toString());
    }
}
