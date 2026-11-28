import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String text = scanner.nextLine();
        String pattern = scanner.nextLine();

        System.out.println(isMatch(text, pattern) ? "YES" : "NO");
    }

    public static boolean isMatch(String text, String pattern) {
        if (pattern.isEmpty()) {
            return text.isEmpty();
        }

        if (pattern.charAt(0) == '*') {
            return isMatch(text, pattern.substring(1)) ||
                    (!text.isEmpty() && (pattern.charAt(0) == text.charAt(0) || pattern.charAt(0) == '?'));
        }

        if (pattern.charAt(0) == '?') {
            return (!text.isEmpty() && (pattern.charAt(0) == text.charAt(0) || pattern.charAt(0) == '?'));
        }

        if (text.isEmpty() || (pattern.charAt(0) != text.charAt(0))) {
            return false;
        }

        return isMatch(text.substring(1), pattern.substring(1));
    }
}
