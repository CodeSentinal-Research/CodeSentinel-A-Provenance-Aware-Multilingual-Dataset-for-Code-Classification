import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        System.out.println(isMinHeap(arr, n) ? "YES" : "NO");
    }

    private static boolean isMinHeap(int[] arr, int n) {
        // Check if the array is a Min Heap
        for (int i = 0; i < n; i++) {
            if (arr[i] > arr[2 * i + 1]) return false;
            if (2 * i + 2 < n && arr[i] > arr[2 * i + 2]) return false;
        }
        return true;
    }
}
