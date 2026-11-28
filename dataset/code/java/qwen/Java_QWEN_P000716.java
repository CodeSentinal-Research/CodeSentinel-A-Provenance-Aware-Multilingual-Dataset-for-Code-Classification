import java.util.*;
public class Main {
    static Map<Character, String> map = new HashMap<>();
    static {
        map.put('2', "abc"); map.put('3', "def"); map.put('4', "ghi");
        map.put('5', "jkl"); map.put('6', "mno"); map.put('7', "pqrs");
        map.put('8', "tuv"); map.put('9', "wxyz");
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String digits = sc.next();
        if(digits.isEmpty()) return;
        letterCombinations(digits, 0, new StringBuilder());
    }
    static void letterCombinations(String digits, int idx, StringBuilder curr) {
        if(idx == digits.length()) {
            System.out.println(curr.toString());
            return;
        }
        String letters = map.get(digits.charAt(idx));
        for(char c : letters.toCharArray()) {
            curr.append(c);
            letterCombinations(digits, idx + 1, curr);
            curr.deleteCharAt(curr.length() - 1);
        }
    }
}
