import java.util.*;

public class Main {
    static int[] heap;
    static int size;

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        size = scanner.nextInt();
        heap = new int[size + 1];
        for (int i = 1; i <= size; i++) {
            heap[i] = scanner.nextInt();
        }
        int q = scanner.nextInt();
        for (int i = 0; i < q; i++) {
            int index = scanner.nextInt();
            int newValue = scanner.nextInt();
            update(index, newValue);
        }
        printHeap();
    }

    static void update(int index, int newValue) {
        int diff = newValue - heap[index];
        heap[index] = newValue;
        index = index + index & 1;
        while (index > 0) {
            heap[index] += diff;
            index = index >> 1;
        }
    }

    static void printHeap() {
        for (int i = 1; i <= size; i++) {
            System.out.print(heap[i] + " ");
        }
        System.out.println();
    }
}
