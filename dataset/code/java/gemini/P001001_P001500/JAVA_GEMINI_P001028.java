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

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int idx = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
            arr[idx] = arr[n - 1];
            n--;
            if (idx < n) {
                int cur = idx;
                while (cur > 0 && arr[cur] > arr[(cur - 1) / 2]) {
                    int t = arr[cur]; arr[cur] = arr[(cur - 1) / 2]; arr[(cur - 1) / 2] = t;
                    cur = (cur - 1) / 2;
                }
                maxHeapify(arr, n, cur);
            }
            for (int i = 0; i < n; i++) {
                System.out.print(arr[i] + (i == n - 1 ? "" : " "));
            }
            System.out.println();
        }
        sc.close();
    }
}