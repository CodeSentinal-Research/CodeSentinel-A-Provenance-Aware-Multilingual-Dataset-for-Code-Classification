import java.util.Scanner;
import java.util.Stack;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int q = scanner.nextInt();
        scanner.nextLine();

        MinStack minStack = new MinStack();

        while (q-- > 0) {
            String operation = scanner.nextLine();
            if (operation.startsWith("push")) {
                int x = Integer.parseInt(operation.split(" ")[1]);
                minStack.push(x);
            } else if (operation.startsWith("pop")) {
                minStack.pop();
           } else if (operation.startsWith("top")) {
                System.out.println(minStack.top());
            } else if (operation.startsWith("getMin")) {
                System.out.println(minStack.getMin());
            }
        }
    }
}

class MinStack {
    private Stack<Integer> stack;
    private Stack<Integer> minStack;

    public MinStack() {
        stack = new Stack<>();
        minStack = new Stack<>();
    }

    public void push(int x) {
        stack.push(x);
        if (minStack.isEmpty() || x <= minStack.peek()) {
            minStack.push(x);
        }
    }

    public void pop() {
        if (stack.peek().equals(minStack.peek())) {
            minStack.pop();
        }
        stack.pop();
    }

    public int top() {
        return stack.peek();
    }

    public int getMin() {
        return minStack.peek();
    }
}
