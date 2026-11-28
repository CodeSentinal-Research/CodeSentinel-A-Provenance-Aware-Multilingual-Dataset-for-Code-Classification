import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        System.out.println(isMaxHeap(arr, n) ? "YES" : "NO");
    }

    public static boolean isMaxHeap(int[] arr, int n) {
        for (int i = 0; i < n; i++) {
            int leftChild = 2 * i + 1;
            int rightChild = 2 * i + 2;
            if (leftChild < n && arr[i] < arr[leftChild]) return false;
            if (rightChild < n && arr[i] < arr[rightChild]) return false;
        }
        return true;
    }
}
