import java.util.Scanner;

public class Main {
    private static final int MAX_DIGITS = 10;
    private static final int MAX_LENGTH = 10;
    private static String[] words = new String[MAX_DIGITS];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String word1 = scanner.next();
        String word2 = scanner.next();
        String word3 = scanner.next();
        if (isValid(word1, word2, word3)) {
            System.out.println(words[0] + " " + words[1] + " " + words[2] + " " + words[3] + " " + words[4] + " " + words[5] + " " + words[6] + " " + words[7] + " " + words[8] + " " + words[9]);
        } else {
            System.out.println("IMPOSSIBLE");
        }
    }

    private static boolean isValid(String word1, String word2, String word3) {
        for (int i = 0; i < MAX_DIGITS; i++) {
            if (i < 4) {
                words[i] = word1.charAt(i) + "";
            } else if (i < 7) {
                words[i] = word2.charAt(i - 4) + "";
            } else {
                words[i] = word3.charAt(i - 7) + "";
            }
        }
        for (int i = 0; i < MAX_DIGITS; i++) {
            if (!words[i].matches("[0-9]+")) {
                return false;
            }
        }
        return true;
    }
}
