import java.util.Stack;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        QueueUsingStacks queue = new QueueUsingStacks();
        for (int i = 0; i < n; i++) {
            String operation = scanner.next();
            if (operation.equals("push")) {
                int x = scanner.nextInt();
                queue.push(x);
            } else if (operation.equals("pop")) {
                System.out.println(queue.pop());
            } else if (operation.equals("peek")) {
                System.out.println(queue.peek());
            } else if (operation.equals("empty")) {
                System.out.println(queue.empty());
            }
        }
    }
}

class QueueUsingStacks {
    Stack<Integer> stack1 = new Stack<>();
    Stack<Integer> stack2 = new Stack<>();

    public void push(int x) {
        while (!stack1.isEmpty()) {
            stack2.push(stack1.pop());
        }
        stack1.push(x);
        while (!stack2.isEmpty()) {
            stack1.push(stack2.pop());
        }
    }

    public int pop() {
        return stack1.pop();
    }

    public int peek() {
        return stack1.peek();
    }

    public boolean empty() {
        return stack1.isEmpty();
    }
}
