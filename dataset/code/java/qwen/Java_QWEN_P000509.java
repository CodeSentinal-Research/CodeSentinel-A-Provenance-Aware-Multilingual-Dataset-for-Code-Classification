import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        Stack<Character> stack = new Stack<>();
        for(char c : s.toCharArray()) {
            if(Character.isDigit(c)) {
                if(!stack.isEmpty()) stack.pop();
            } else {
                stack.push(c);
            }
        }
        StringBuilder sb = new StringBuilder();
        for(char c : stack) sb.append(c);
        System.out.println(sb.toString());
    }
}
