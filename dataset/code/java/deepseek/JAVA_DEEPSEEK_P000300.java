import java.util.*;

public class Main {
    private static Map<Character, String> phone = new HashMap<Character, String>() {{
        put('2', "abc");
        put('3', "def");
        put('4', "ghi");
        put('5', "jkl");
        put('6', "mno");
        put('7', "pqrs");
        put('8', "tuv");
        put('9', "wxyz");
    }};

    public static List<String> letterCombinations(String digits) {
        List<String> result = new ArrayList<>();
        if(digits == null || digits.length() == 0)
            return result;
        backtrack(result, digits, "", 0);
        return result;
    }

    private static void backtrack(List<String> result, String digits, String current, int index) {
        if(index == digits.length()) {
            result.add(current);
            return;
        }
        String letters = phone.get(digits.charAt(index));
        for(int i = 0; i < letters.length(); i++) {
            backtrack(result, digits, current + letters.charAt(i), index + 1);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String digits = scanner.next();
        List<String> result = letterCombinations(digits);
        for(String str : result) {
            System.out.println(str);
        }
    }
}
