import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        Set<String> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            String word = scanner.nextLine();
            set.add(word);
        }

        List<String> list = new ArrayList<>(set);
        Collections.sort(list, Comparator.comparing(String::length));

        int maxLength = 0;
        for (String word : list) {
            if (word.length() + maxLength > maxLength) {
                maxLength += word.length();
            } else {
                break;
            }
        }

        System.out.println(maxLength);
    }
}
