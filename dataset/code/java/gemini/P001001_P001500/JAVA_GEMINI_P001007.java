import java.util.Scanner;

public class Solution {
    private static void maxHeapify(int[] arr, int n, int i) {
        int largest = i, l = 2 * i + 1, r = 2 * i + 2;
        if (l < n && arr[l] > arr[largest]) largest = l;
        if (r < n && arr[r] > arr[largest]) largest = r;
        if (largest != i) {
            int t = arr[i]; arr[i] = arr[largest]; arr[largest] = t;
            maxHeapify(arr, n, largest);
        }
    }

    public static void replaceRoot(int[] arr, int x) {
        arr[0] = x;
        maxHeapify(arr, arr.length, 0);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int x = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
            replaceRoot(arr, x);
            for (int i = 0; i < n; i++) {
                System.out.print(arr[i] + (i == n - 1 ? "" : " "));
            }
            System.out.println();
        }
        sc.close();
    }
}