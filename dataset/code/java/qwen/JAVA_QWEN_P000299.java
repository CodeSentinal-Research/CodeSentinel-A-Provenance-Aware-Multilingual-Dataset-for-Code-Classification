import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        
        List<String> result = new ArrayList<>();
        generateParentheses(n, 0, 0, "", result);
        
        for (String s : result) {
            System.out.println(s);
        }
    }
    
    private static void generateParentheses(int n, int open, int close, String current, List<String> result) {
        if (current.length() == 2 * n) {
            result.add(current);
            return;
        }
        
        if (open < n) {
            generateParentheses(n, open + 1, close, current + "(", result);
        }
        if (close < open) {
            generateParentheses(n, open, close + 1, current + ")", result);
        }
    }
}
