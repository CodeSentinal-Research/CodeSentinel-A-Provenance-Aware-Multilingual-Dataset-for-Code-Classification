import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        Stack<Integer> stack = new Stack<>();
        stack.push(1);
        for(char c : s.toCharArray()) {
            if(c == '#') {
                if(stack.isEmpty()) { System.out.println("NO"); return; }
                stack.pop();
            } else {
                stack.push(2);
            }
        }
        System.out.println(stack.size() == 1 && stack.peek() == 1 ? "YES" : "NO");
    }
}
