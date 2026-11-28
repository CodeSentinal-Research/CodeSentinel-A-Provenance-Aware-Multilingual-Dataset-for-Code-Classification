import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        List<String> strings = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            strings.add(scanner.nextLine());
        }

        Set<Character> commonCharacters = getCommonCharacters(strings);

        commonCharacters.forEach(System.out::println);
    }

    private static Set<Character> getCommonCharacters(List<String> strings) {
        Set<Character> result = new HashSet<>();

        for (String string : strings) {
            Set<Character> current = new HashSet<>();
            for (char c : string.toCharArray()) {
                current.add(c);
            }

            if (result.isEmpty()) {
                result.addAll(current);
            } else {
                result.retainAll(current);
            }
        }

        return result;
    }
}
