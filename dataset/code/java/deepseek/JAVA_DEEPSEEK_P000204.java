import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        waveSort(arr, n);
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }

    private static void waveSort(int[] arr, int n) {
        Arrays.sort(arr);
        for (int i = 0; i < n - 1; i += 2) {
            swap(arr, i, i + 1);
        }
    }

    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
