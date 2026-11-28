import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String num = sc.next();
        int k = sc.nextInt();
        Stack<Character> stack = new Stack<>();
        for(char c : num.toCharArray()) {
            while(k > 0 && !stack.isEmpty() && stack.peek() > c) {
                stack.pop();
                k--;
            }
            stack.push(c);
        }
        while(k > 0) { stack.pop(); k--; }
        StringBuilder sb = new StringBuilder();
        for(char c : stack) sb.append(c);
        while(sb.length() > 1 && sb.charAt(0) == '0') sb.deleteCharAt(0);
        System.out.println(sb.toString());
    }
}
