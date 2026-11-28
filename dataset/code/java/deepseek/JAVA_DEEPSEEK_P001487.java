import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        scanner.nextLine();

        String pattern = scanner.nextLine();

        for (int i = 0; i < N; i++) {
            String query = scanner.nextLine();
            System.out.println(isMatch(query, pattern));
        }

        scanner.close();
    }

    private static String isMatch(String query, String pattern) {
        int patternIndex = 0;
        for (int i = 0; i < query.length(); i++) {
            if (patternIndex < pattern.length() && query.charAt(i) == pattern.charAt(patternIndex)) {
                patternIndex++;
            } else if (i > 0 && Character.isUpperCase(query.charAt(i)) && Character.isLowerCase(query.charAt(i - 1))) {
                return "NO";
            }
        }
        return patternIndex == pattern.length() ? "YES" : "NO";
    }
}
