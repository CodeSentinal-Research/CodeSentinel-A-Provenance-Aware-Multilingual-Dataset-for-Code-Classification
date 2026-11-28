import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        int n = 3; // Replace with the actual input
        List<String> result = generateParenthesis(n);
        for (String s : result) {
            System.out.println(s);
        }
    }

    public static List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<>();
        backtrack(result, "", 0, 0, n);
        return result;
    }

    private static void backtrack(List<String> list, String str, int open, int close, int max){
        if(str.length() == max * 2){
            list.add(str);
            return;
        }
        if(open < max){
            backtrack(list, str+"(", open+1, close, max);
       }
        if(close < open){
            backtrack(list, str+")", open, close+1, max);
        }
    }
}
