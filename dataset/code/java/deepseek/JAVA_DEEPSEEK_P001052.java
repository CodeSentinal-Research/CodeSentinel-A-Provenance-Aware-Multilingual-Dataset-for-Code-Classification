import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        scanner.close();
        if (isValidHeap(arr, n)) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }

    private static boolean isValidHeap(int[] arr, int n) {
        for (int i = 0; i < n; i++) {
            int leftChild = 2 * i + 1;
            int rightChild = 2 * i + 2;
            if (leftChild < n && arr[leftChild] > arr[i]) {
                return false;
            }
            if (rightChild < n && arr[rightChild] > arr[i]) {
                return false;
            }
        }
        return true;
    }
}
