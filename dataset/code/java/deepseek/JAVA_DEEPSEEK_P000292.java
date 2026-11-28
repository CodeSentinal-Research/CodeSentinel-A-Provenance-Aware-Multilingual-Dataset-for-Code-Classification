import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String encoded = scanner.next();
        System.out.println(decodeString(encoded));
    }

    public static String decodeString(String s) {
        Stack<String> stack = new Stack<>();
        int num = 0;
        for (char c : s.toCharArray()) {
            if (c == ']') {
                StringBuilder sb = new StringBuilder();
                while (!stack.peek().equals("[")) {
                    sb.insert(0, stack.pop());
                }
                stack.pop(); // pop the '['

                int repeat = 0;
                while (!stack.isEmpty() && Character.isDigit(stack.peek().charAt(0))) {
                    repeat = repeat * 10 + Integer.parseInt(stack.pop());
                }

                String str = sb.toString();
                while (repeat-- > 0) {
                    stack.push(str);
                }
            } else {
                stack.push(String.valueOf(c));
            }
        }

        return String.join("", stack);
    }
}
