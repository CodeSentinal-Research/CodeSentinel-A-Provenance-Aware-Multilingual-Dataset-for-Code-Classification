import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String sentence1 = scanner.nextLine();
        String sentence2 = scanner.nextLine();
        int P = scanner.nextInt();
        scanner.nextLine(); // consume the newline character

        Map<String, String> map = new HashMap<>();
        for (int i = 0; i < P; i++) {
            String[] pair = scanner.nextLine().split(" ");
            map.put(pair[0], pair[1]);
        }

        System.out.println(areSentencesSimilar(sentence1, sentence2, map) ? "YES" : "NO");
    }

    private static boolean areSentencesSimilar(String sentence1, String sentence2, Map<String, String> map) {
        String[] words1 = sentence1.split(" ");
        String[] words2 = sentence2.split(" ");

        if (words1.length != words2.length) {
            return false;
        }

        for (int i = 0; i < words1.length; i++) {
            if (!words1[i].equals(words2[i])) {
                if (!map.containsKey(words1[i]) || !map.get(words1[i]).equals(words2[i])) {
                    return false;
                }
            }
        }

        return true;
    }
}
