import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String allowedChars = scanner.nextLine();
        int numWords = scanner.nextInt();
        scanner.nextLine(); // consume the newline character

        int count = 0;
        for (int i = 0; i < numWords; i++) {
            String word = scanner.nextLine();
            if (isConsistent(word, allowedChars)) {
                count++;
            }
        }

        System.out.println(count);
    }

    private static boolean isConsistent(String word, String allowedChars) {
        for (char c : word.toCharArray()) {
            if (!allowedChars.contains(String.valueOf(c))) {
                return false;
            }
        }
        return true;
    }
}
