import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine().replaceAll("\\s+", "");
        Stack<Long> stack = new Stack<>();
        long num = 0;
        char op = '+';
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (Character.isDigit(c)) {
                num = num * 10 + (c - '0');
            }
            if (!Character.isDigit(c) && c != ' ' || i == s.length() - 1) {
                if (op == '+') stack.push(num);
                else if (op == '-') stack.push(-num);
                else if (op == '*') stack.push(stack.pop() * num);
                else if (op == '/') stack.push(stack.pop() / num);
                op = c;
                num = 0;
            }
        }
        long sum = 0;
        for (long x : stack) sum += x;
        System.out.println(sum);
    }
}
