import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            queue.add(scanner.nextInt());
        }
        Queue<Integer> result = interleave(queue);
        while (!result.isEmpty()) {
            System.out.print(result.poll() + " ");
        }
    }

    public static Queue<Integer> interleave(Queue<Integer> queue) {
        Queue<Integer> firstHalf = new LinkedList<>();
        Queue<Integer> secondHalf = new LinkedList<>();
        int halfSize = queue.size() / 2;
        for (int i = 0; i < halfSize; i++) {
            firstHalf.add(queue.poll());
        }
        while (!queue.isEmpty()) {
            secondHalf.add(queue.poll());
        }
        Queue<Integer> result = new LinkedList<>();
        while (!firstHalf.isEmpty() && !secondHalf.isEmpty()) {
            result.add(firstHalf.poll());
            result.add(secondHalf.poll());
        }
        while (!firstHalf.isEmpty()) {
            result.add(firstHalf.poll());
        }
        while (!secondHalf.isEmpty()) {
            result.add(secondHalf.poll());
        }
        return result;
    }
}
