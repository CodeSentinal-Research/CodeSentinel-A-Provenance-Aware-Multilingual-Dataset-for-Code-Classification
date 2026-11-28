import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String[] tokens = new String[n];
        for(int i=0; i<n; i++) tokens[i] = sc.next();
        
        Stack<Integer> stack = new Stack<>();
        for(String t : tokens) {
            if(t.equals("+")) {
                int b = stack.pop(), a = stack.pop();
                stack.push(a + b);
            } else if(t.equals("-")) {
                int b = stack.pop(), a = stack.pop();
                stack.push(a - b);
            } else if(t.equals("*")) {
                int b = stack.pop(), a = stack.pop();
                stack.push(a * b);
            } else if(t.equals("/")) {
                int b = stack.pop(), a = stack.pop();
                stack.push(a / b);
            } else {
                stack.push(Integer.parseInt(t));
            }
        }
        System.out.println(stack.pop());
    }
}
