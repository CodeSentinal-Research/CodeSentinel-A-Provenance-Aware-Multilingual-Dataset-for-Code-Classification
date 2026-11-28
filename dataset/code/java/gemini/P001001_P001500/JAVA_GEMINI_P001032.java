import java.util.Scanner;

public class Solution {
    private static void minHeapify(int[] arr, int n, int i) {
        int smallest = i, l = 2 * i + 1, r = 2 * i + 2;
        if (l < n && arr[l] < arr[smallest]) smallest = l;
        if (r < n && arr[r] < arr[smallest]) smallest = r;
        if (smallest != i) {
            int t = arr[i]; arr[i] = arr[smallest]; arr[smallest] = t;
            minHeapify(arr, n, smallest);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int x = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
            arr[0] = x;
            minHeapify(arr, n, 0);
            for (int i = 0; i < n; i++) {
                System.out.print(arr[i] + (i == n - 1 ? "" : " "));
            }
            System.out.println();
        }
        sc.close();
    }
}