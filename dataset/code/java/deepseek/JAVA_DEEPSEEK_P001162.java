import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String text = scanner.nextLine();
        String pattern = scanner.nextLine();

        System.out.println(isMatch(text, pattern));
    }

    public static boolean isMatch(String s, String p) {
        return isMatchRec(s, p, 0, 0);
    }

    public static boolean isMatchRec(String s, String p, int i, int j) {
        if (i == s.length() && j == p.length()) {
            return true;
        }

        if (j == p.length()) {
            return false;
        }

        if (i == s.length()) {
            while (j + 1 < p.length() && p.charAt(j + 1) == '*') {
                j += 2;
            }
            return isMatchRec(s, p, i, j + 1);
        }

        if (p.charAt(j) == '*') {
            return isMatchRec(s, p, i, j + 1);
        }

        if (p.charAt(j) == '.' || s.charAt(i) == p.charAt(j)) {
            return isMatchRec(s, p, i + 1, j + 1);
        }

        return false;
    }
}
