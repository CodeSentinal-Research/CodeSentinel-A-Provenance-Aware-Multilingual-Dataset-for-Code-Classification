import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        System.out.println(findMax(arr, 0, n - 1));
    }

    private static int findMax(int[] arr, int low, int high) {
        if (low == high) {
            return arr[low];
        }
        int mid = (low + high) / 2;
        if (arr[mid] > arr[mid + 1]) {
            return findMax(arr, low, mid);
        } else {
            return findMax(arr, mid + 1, high);
        }
    }
}
