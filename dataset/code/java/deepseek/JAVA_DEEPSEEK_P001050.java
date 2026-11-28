import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            arr[i] = scanner.nextInt();
        }
        scanner.close();
        buildMinHeap(arr, n);
        for (int i = 1; i <= n; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    private static void buildMinHeap(int[] arr, int n) {
        for (int i = n / 2; i >= 1; i--) {
            minHeapify(arr, n, i);
        }
    }

    private static void minHeapify(int[] arr, int n, int i) {
        int smallest = i;
        int left = 2 * i;
        int right = 2 * i + 1;
        if (left <= n && arr[left] < arr[smallest]) {
            smallest = left;
        }
        if (right <= n && arr[right] < arr[smallest]) {
            smallest = right;
        }
        if (smallest != i) {
            int temp = arr[i];
            arr[i] = arr[smallest];
            arr[smallest] = temp;
            minHeapify(arr, n, smallest);
        }
    }
}
