import java.util.Stack;

public class Main {
    public static int calculate(String s) {
        Stack<Integer> stack = new Stack<>();
        int num = 0;
        char sign = '+';
        for(int i = 0; i < s.length(); i++) {
            if(Character.isDigit(s.charAt(i))) {
                num = num * 10 + s.charAt(i) - '0';
            } else if(s.charAt(i) == '(') {
                int j = i + 1;
                int count = 1;
                while(count != 0) {
                    if(s.charAt(j) == '(') count++;
                    if(s.charAt(j) == ')') count--;
                    j++;
                }
                num = calculate(s.substring(i + 1, j - 1));
                i = j - 1;
            } else if(s.charAt(i) != ' ' || i == s.length() - 1) {
                switch(sign) {
                    case '+':
                        stack.push(num);
                        break;
                    case '-':
                        stack.push(-num);
                        break;
                    case '*':
                        stack.push(stack.pop() * num);
                        break;
                    case '/':
                        stack.push(stack.pop() / num);
                        break;
                }
                sign = s.charAt(i);
                num = 0;
            }
        }
        int result = 0;
        while(!stack.isEmpty()) {
            result += stack.pop();
        }
        return result;
    }

    public static void main(String[] args) {
        System.out.println(calculate("10 + 5 * 2"));
    }
}