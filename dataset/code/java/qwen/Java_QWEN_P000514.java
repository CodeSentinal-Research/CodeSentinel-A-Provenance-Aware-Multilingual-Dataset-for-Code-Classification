import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String expression = sc.next();
        Stack<Character> stack = new Stack<>();
        for(int i=expression.length()-1; i>=0; i--) {
            char c = expression.charAt(i);
            if(c == '?') {
                char first = stack.pop();
                char second = stack.pop();
                char condition = stack.pop();
                stack.push(condition == 'T' ? first : second);
            } else {
                stack.push(c);
            }
        }
        System.out.println(stack.pop());
    }
}
