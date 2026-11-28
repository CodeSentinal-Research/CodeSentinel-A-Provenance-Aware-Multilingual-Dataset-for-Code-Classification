import java.util.*;
public class Solution {
    static boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        for (char c : s.toCharArray()) {
            if (c == '(' || c == '{' || c == '[') st.push(c);
            else {
                if (st.isEmpty()) return false;
                if (c == ')' && st.pop() != '(') return false;
                if (c == '}' && st.pop() != '{') return false;
                if (c == ']' && st.pop() != '[') return false;
            }
        }
        return st.isEmpty();
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            System.out.println(isValid(s) ? "true" : "false");
        }
    }
}