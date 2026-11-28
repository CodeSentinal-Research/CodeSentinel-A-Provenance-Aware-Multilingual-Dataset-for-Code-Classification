import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        String expression = System.console().readLine();
        System.out.println(parseBoolExpr(expression));
    }

    private static boolean parseBoolExpr(String expression) {
        Stack<Character> stack = new Stack<>();
        for (char c : expression.toCharArray()) {
            if (c == ')') {
                StringBuilder sb = new StringBuilder();
                while (stack.peek() != '(') {
                    sb.append(stack.pop());
                }
                stack.pop();
                int tCount = 0, fCount = 0;
                for (char ch : sb.toString().toCharArray()) {
                    if (ch == 't') {
                        tCount++;
                    } else if (ch == 'f') {
                        fCount++;
                    }
                }
                if (stack.peek() == '&') {
                    stack.pop();
                    stack.push(tCount > 0 ? 't' : 'f');
                } else if (stack.peek() == '|') {
                    stack.pop();
                    stack.push(tCount > 0 ? 't' : 'f');
                } else if (stack.peek() == '!') {
                    stack.pop();
                    stack.push(tCount == 0 ? 't' : 'f');
                }
            } else {
                stack.push(c);
            }
        }
        return stack.peek() == 't';
    }
}
