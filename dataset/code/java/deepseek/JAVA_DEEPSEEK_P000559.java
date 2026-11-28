import java.util.*;
import java.lang.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < N; i++) {
            queue.add(sc.nextInt());
        }
        int K = sc.nextInt();
        queue = reverseKElements(queue, K);
        while (!queue.isEmpty()) {
            System.out.println(queue.poll());
        }
    }

    public static Queue<Integer> reverseKElements(Queue<Integer> queue, int K) {
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < K; i++) {
            stack.push(queue.poll());
        }
        while (!stack.isEmpty()) {
            queue.add(stack.pop());
        }
        for (int i = 0; i < queue.size() - K; i++) {
            queue.add(queue.poll());
        }
        return queue;
    }
}
