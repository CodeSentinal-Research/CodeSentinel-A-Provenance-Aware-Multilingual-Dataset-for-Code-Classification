import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            arr[i] = scanner.nextInt();
        }
        int i = scanner.nextInt();
        int newValue = scanner.nextInt();
        arr[i] = newValue;
        heapify(arr, n, i);
        for (int j = 1; j <= n; j++) {
            System.out.print(arr[j] + " ");
        }
    }

    private static void heapify(int[] arr, int n, int i) {
        int largest = i;
        int leftChild = 2 * i;
        int rightChild = 2 * i + 1;
        if (leftChild <= n && arr[leftChild] > arr[largest]) {
            largest = leftChild;
        }
        if (rightChild <= n && arr[rightChild] > arr[largest]) {
            largest = rightChild;
        }
        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            heapify(arr, n, largest);
        }
    }
}
