import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String digits = sc.next();
        
        String[] mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        List<String> result = new ArrayList<>();
        
        if (digits.isEmpty()) return;
        
        backtrack(digits, 0, "", mapping, result);
        
        for (String s : result) {
            System.out.println(s);
        }
    }
    
    private static void backtrack(String digits, int index, String current, String[] mapping, List<String> result) {
        if (index == digits.length()) {
            result.add(current);
            return;
        }
        
        int digit = digits.charAt(index) - '0';
        String letters = mapping[digit];
        
        for (char c : letters.toCharArray()) {
            backtrack(digits, index + 1, current + c, mapping, result);
        }
    }
}
