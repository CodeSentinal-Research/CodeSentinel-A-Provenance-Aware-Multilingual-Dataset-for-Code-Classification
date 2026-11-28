import java.util.*;

public class Main {
    private static final Map<Character, String> digitToChar = new HashMap<Character, String>() {{
        put('2', "abc");
        put('3', "def");
        put('4', "ghi");
        put('5', "jkl");
        put('6', "mno");
        put('7', "pqrs");
        put('8', "tuv");
        put('9', "wxyz");
    }};

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String digits = scanner.nextLine();
        backtrack(digits, 0, "");
    }

    private static void backtrack(String digits, int index, String combination) {
        if (index == digits.length()) {
            System.out.println(combination);
            return;
        }

        String letters = digitToChar.get(digits.charAt(index));
        for (char letter : letters.toCharArray()) {
            backtrack(digits, index + 1, combination + letter);
        }
    }
}
