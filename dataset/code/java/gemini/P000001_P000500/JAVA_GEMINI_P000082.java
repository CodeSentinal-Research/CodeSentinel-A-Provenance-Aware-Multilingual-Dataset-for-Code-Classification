import java.util.Scanner;

public class SpecialSymbolChecker {

    /**
     * Checks whether the specified character is a special symbol.
     * A character is considered a special symbol if it is not a letter, 
     * not a digit, and not a whitespace character.
     *
     * @param ch the character to check
     * @return true if the character is a special symbol, false otherwise
     */
    public static boolean isSpecialSymbol(char ch) {
        return !Character.isLetterOrDigit(ch) && !Character.isWhitespace(ch);
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNextLine()) {
            String line = scanner.nextLine();
            if (!line.isEmpty()) {
                char ch = line.charAt(0);
                if (isSpecialSymbol(ch)) {
                    System.out.println(ch + " is a special symbol.");
                } else {
                    System.out.println(ch + " is not a special symbol.");
                }
            } else {
                System.out.println("Empty input.");
            }
        }
        scanner.close();
    }
}