import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        Stack<StringBuilder> stack = new Stack<>();
        stack.push(new StringBuilder());
        for (char c : s.toCharArray()) {
            if (c == '(') {
                stack.push(new StringBuilder());
            } else if (c == ')') {
                StringBuilder tmp = stack.pop().reverse();
                stack.peek().append(tmp);
           } else {
                stack.peek().append(c);
            }
        }
        System.out.println(stack.pop().toString());
    }
}