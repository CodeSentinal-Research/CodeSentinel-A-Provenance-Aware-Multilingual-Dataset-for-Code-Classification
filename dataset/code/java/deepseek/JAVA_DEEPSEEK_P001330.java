import java.util.*;

public class Main {
    private static List<List<String>> result = new ArrayList<>();
    private static List<String> path = new ArrayList<>();

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        scanner.close();

        partition(s, 0);
        result.stream().forEach(System.out::println);
    }

    private static void partition(String s, int start) {
        if (start == s.length()) {
            result.add(new ArrayList<>(path));
            return;
        }

        for (int i = start; i < s.length(); i++) {
            String substring = s.substring(start, i + 1);
            if (isPalindrome(substring)) {
                path.add(substring);
                partition(s, i + 1);
                path.remove(path.size() - 1);
            }
        }
    }

    private static boolean isPalindrome(String s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}
