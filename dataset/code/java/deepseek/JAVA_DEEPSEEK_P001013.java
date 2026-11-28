import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
    private static PriorityQueue<Integer> maxHeap;
    private static PriorityQueue<Integer> minHeap;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();

        maxHeap = new PriorityQueue<>((a, b) -> b - a);
        minHeap = new PriorityQueue<>();

        for (int i = 0; i < n; i++) {
            int num = scanner.nextInt();
            scanner.nextLine();

            addNumber(num);
            System.out.println(getMedian());
        }

        scanner.close();
    }

    private static void addNumber(int num) {
        maxHeap.add(num);
        minHeap.add(maxHeap.poll());

        if (maxHeap.size() < minHeap.size()) {
            maxHeap.add(minHeap.poll());
        }
    }

    private static double getMedian() {
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.peek();
        } else {
            return (maxHeap.peek() + minHeap.peek()) / 2.0;
        }
    }
}
