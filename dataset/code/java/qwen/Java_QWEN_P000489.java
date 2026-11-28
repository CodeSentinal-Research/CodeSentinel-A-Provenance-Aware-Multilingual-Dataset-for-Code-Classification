import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int q = sc.nextInt();
        Stack<int[]> stack = new Stack<>();
        for(int i=0; i<q; i++) {
            String op = sc.next();
            if(op.equals("push")) {
                int val = sc.nextInt();
                int min = stack.isEmpty() ? val : Math.min(val, stack.peek()[1]);
                stack.push(new int[]{val, min});
            } else if(op.equals("pop")) {
                stack.pop();
            } else if(op.equals("top")) {
                System.out.println(stack.peek()[0]);
            } else if(op.equals("getMin")) {
                System.out.println(stack.peek()[1]);
            }
        }
    }
}
