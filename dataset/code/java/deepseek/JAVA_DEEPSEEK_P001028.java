import java.util.Scanner;
import java.util.PriorityQueue;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        PriorityQueue<Integer> queue = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            queue.add(scanner.nextInt());
        }
        int indexToDelete = scanner.nextInt();
        deleteElement(queue, indexToDelete);
    }

    private static void deleteElement(PriorityQueue<Integer> queue, int index) {
        int[] indices = new int[queue.size()];
        int i = 0;
        for (Integer element : queue) {
            indices[i++] = element;
        }
        queue.remove(index);
        if (!queue.isEmpty()) {
            PriorityQueue<Integer> newQueue = new PriorityQueue<>();
            for (int j = 0; j < queue.size(); j++) {
                if (j != index) {
                    newQueue.add(queue.poll());
                }
            }
            deleteElement(newQueue, indices[index]);
        } else {
            System.out.println("Heap is empty");
        }
    }
}
