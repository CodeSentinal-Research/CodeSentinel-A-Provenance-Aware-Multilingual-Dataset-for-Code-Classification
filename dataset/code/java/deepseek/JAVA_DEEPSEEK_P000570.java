import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < N; i++) {
            queue.add(scanner.nextInt());
        }
        int K = scanner.nextInt();
        queue = rotateLeft(queue, K);
        for (Integer num : queue) {
            System.out.print(num + " ");
        }
    }

    public static Queue<Integer> rotateLeft(Queue<Integer> queue, int K) {
        Queue<Integer> newQueue = new LinkedList<>();
        for (int i = 0; i < queue.size(); i++) {
            newQueue.add(queue.poll());
        }
        for (int i = 0; i < K; i++) {
            newQueue.add(newQueue.poll());
        }
        return newQueue;
    }
}
