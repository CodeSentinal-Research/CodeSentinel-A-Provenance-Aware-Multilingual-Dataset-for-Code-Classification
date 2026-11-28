import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        Stack<Integer> stack = new Stack<>();
        for(char c : s.toCharArray()) {
            if(c == '(') stack.push(0);
            else if(c == ')') {
                int v = stack.pop();
                if(v == 0) stack.push(1);
                else {
                    int sum = 0;
                    while(!stack.isEmpty() && stack.peek() != 0) sum += stack.pop();
                    if(!stack.isEmpty()) stack.pop(); // pop 0
                    stack.push(2 * (sum + v));
                }
            } else {
                // Should not happen in valid input of just ()
            }
        }
        int sum = 0;
        while(!stack.isEmpty()) sum += stack.pop();
        System.out.println(sum);
    }
}
