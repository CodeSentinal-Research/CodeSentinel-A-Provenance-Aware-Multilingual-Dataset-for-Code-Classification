import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        String expression = "T?F?T:F:T";
        System.out.println(ternaryExpressionParser(expression));
    }

    public static char ternaryExpressionParser(String expression) {
        Stack<Character> stack = new Stack<>();
        for (int i = expression.length() - 1; i >= 0; i--) {
            char c = expression.charAt(i);
            if (c == 'T' || c == 'F' || c == '?') {
                stack.push(c);
            } else if (c == ':') {
                char first = stack.pop();
                char second = stack.pop();
                stack.pop(); // pop the '?'
                if (first == 'T' && second == 'F') {
                    stack.push(stack.pop()); // push the third operand
                } else {
                    stack.push(first); // push the first operand
                }
            }
        }
        return stack.pop();
    }
}
