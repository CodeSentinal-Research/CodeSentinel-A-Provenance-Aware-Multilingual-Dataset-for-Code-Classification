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
        heapify(arr, i);
        for (int j = 1; j <= n; j++) {
            System.out.print(arr[j] + " ");
        }
    }

    private static void heapify(int[] arr, int i) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int largest = i;
        if (left <= arr.length - 1 && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right <= arr.length - 1 && arr[right] > arr[largest]) {
            largest = right;
        }
        if (largest != i) {
            int temp = arr[i];
            arr[i] = arr[largest];
            arr[largest] = temp;
            heapify(arr, largest);
        }
    }
}
