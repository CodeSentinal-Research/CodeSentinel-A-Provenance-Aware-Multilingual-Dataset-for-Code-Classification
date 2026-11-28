import java.util.Scanner;

public class Solution {
    public static void rotateRight(int[] arr, int k) {
        if (arr == null || arr.length == 0) return;
        int n = arr.length;
        k = k % n;
        reverse(arr, 0, n - 1);
        reverse(arr, 0, k - 1);
        reverse(arr, k, n - 1);
    }

    private static void reverse(int[] arr, int l, int r) {
        while (l < r) {
            int tmp = arr[l];
            arr[l++] = arr[r];
            arr[r--] = tmp;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
            rotateRight(arr, k);
            for (int i = 0; i < n; i++) {
                System.out.print(arr[i] + (i == n - 1 ? "" : " "));
            }
            System.out.println();
        }
        sc.close();
    }
}