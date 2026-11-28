import java.util.LinkedList;
import java.util.Queue;

public class Main {
    public static void main(String[] args) {
        StackUsingQueues stack = new StackUsingQueues();
        stack.push(1);
        stack.push(2);
        stack.push(3);
        System.out.println(stack.top()); // prints 3
        System.out.println(stack.pop()); // prints 3
        System.out.println(stack.empty()); // prints false
        stack.push(4);
        System.out.println(stack.pop()); // prints 4
        System.out.println(stack.pop()); // prints 2
        System.out.println(stack.empty()); // prints false
        System.out.println(stack.pop()); // prints 1
        System.out.println(stack.empty()); // prints true
    }
}

class StackUsingQueues {
    Queue<Integer> queue1;
    Queue<Integer> queue2;

    public StackUsingQueues() {
        queue1 = new LinkedList<>();
        queue2 = new LinkedList<>();
    }

    public void push(int x) {
        queue2.add(x);
        while (!queue1.isEmpty()) {
            queue2.add(queue1.poll());
        }
        Queue<Integer> temp = queue1;
        queue1 = queue2;
        queue2 = temp;
    }

    public int pop() {
        return queue1.poll();
    }

    public int top() {
        return queue1.peek();
    }

    public boolean empty() {
        return queue1.isEmpty();
    }
}
