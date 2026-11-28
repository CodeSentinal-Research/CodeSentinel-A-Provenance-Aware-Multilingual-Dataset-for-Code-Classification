import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] heap = new int[n];
        for (int i = 0; i < n; i++) {
            heap[i] = sc.nextInt();
        }
        int replace = sc.nextInt();

        heap[0] = replace;
        minHeapify(heap, 0, n);

        for (int i : heap) {
            System.out.print(i + " ");
        }
    }

    private static void minHeapify(int[] heap, int i, int n) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < n && heap[left] < heap[smallest]) {
            smallest = left;
        }

        if (right < n && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest != i) {
            swap(heap, i, smallest);
            minHeapify(heap, smallest, n);
        }
    }

    private static void swap(int[] heap, int i, int j) {
        int temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
   }
}
