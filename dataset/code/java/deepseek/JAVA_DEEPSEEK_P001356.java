import java.util.*;

public class Main {
    static int maxUniqueSubstrings;
    static Set<String> uniqueSubstrings;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        maxUniqueSubstrings = input.length();
        uniqueSubstrings = new HashSet<>();
        backtrack(input, 0, "");
        System.out.println(maxUniqueSubstrings);
    }

    private static void backtrack(String s, int index, String curr) {
        if (index == s.length()) {
            uniqueSubstrings.add(curr);
            return;
        }

        for (int i = index; i < s.length(); i++) {
            String substring = s.substring(index, i + 1);
            if (!uniqueSubstrings.contains(substring)) {
                uniqueSubstrings.add(substring);
                maxUniqueSubstrings = Math.max(maxUniqueSubstrings, uniqueSubstrings.size());
                backtrack(s, i + 1, curr + substring);
            }
        }
    }
}
