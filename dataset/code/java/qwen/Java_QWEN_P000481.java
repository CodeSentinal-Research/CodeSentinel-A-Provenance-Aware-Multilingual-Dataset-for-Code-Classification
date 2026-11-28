import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Stack<Integer> stack = new Stack<>();
        for(int i=0; i<n; i++) {
            String op = sc.next();
            if(op.equals("+")) {
                int top = stack.pop();
                int newTop = top + stack.peek();
                stack.push(top);
                stack.push(newTop);
            } else if(op.equals("D")) {
                stack.push(2 * stack.peek());
            } else if(op.equals("C")) {
                stack.pop();
            } else {
                stack.push(Integer.parseInt(op));
            }
        }
        int sum = 0;
        for(int x : stack) sum += x;
        System.out.println(sum);
    }
}
