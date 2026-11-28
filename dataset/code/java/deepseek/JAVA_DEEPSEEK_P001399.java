import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String sentence1 = scanner.nextLine();
        String sentence2 = scanner.nextLine();
        Set<String> set1 = new HashSet<>(Arrays.asList(sentence1.split(" ")));
        Set<String> set2 = new HashSet<>(Arrays.asList(sentence2.split(" ")));
        for (String word : set1) {
            if (!set2.contains(word)) {
                System.out.println(word);
            }
        }
        for (String word : set2) {
            if (!set1.contains(word)) {
                System.out.println(word);
            }
        }
    }
}
