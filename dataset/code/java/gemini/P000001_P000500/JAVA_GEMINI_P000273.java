import java.util.*;
public class Solution {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        if (scanner.hasNext()) {
            String s = scanner.next();
            Deque<Character> stack = new ArrayDeque<>();
            boolean valid = true;
            for (char c : s.toCharArray()) {
                if (c == '(' || c == '{' || c == '[') stack.push(c);
                else {
                    if (stack.isEmpty()) { valid = false; break; }
                    char top = stack.pop();
                    if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                        valid = false; break;
                    }
                }
            }
            System.out.println(valid && stack.isEmpty() ? "Valid" : "Invalid");
        }
    }
}