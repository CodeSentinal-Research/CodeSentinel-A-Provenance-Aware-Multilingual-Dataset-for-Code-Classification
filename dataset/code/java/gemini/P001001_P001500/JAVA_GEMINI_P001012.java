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

    public static int[] mergeMinHeaps(int[] a, int[] b) {
        int n = a.length + b.length;
        int[] merged = new int[n];
        System.arraycopy(a, 0, merged, 0, a.length);
        System.arraycopy(b, 0, merged, a.length, b.length);
        for (int i = n / 2 - 1; i >= 0; i--) {
            minHeapify(merged, n, i);
        }
        return merged;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) a[i] = sc.nextInt();
            int[] b = new int[m];
            for (int i = 0; i < m; i++) b[i] = sc.nextInt();
            int[] res = mergeMinHeaps(a, b);
            for (int i = 0; i < res.length; i++) {
                System.out.print(res[i] + (i == res.length - 1 ? "" : " "));
            }
            System.out.println();
        }
        sc.close();
    }
}