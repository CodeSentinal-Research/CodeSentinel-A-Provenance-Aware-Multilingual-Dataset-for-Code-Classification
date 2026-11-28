import java.util.Scanner;

public class Solution {
    public static void decreaseKey(int[] arr, int idx, int newVal) {
        arr[idx] = newVal;
        int i = idx;
        while (i > 0) {
            int p = (i - 1) / 2;
            if (arr[i] < arr[p]) {
                int t = arr[i]; arr[i] = arr[p]; arr[p] = t;
                i = p;
            } else {
                break;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            int idx = sc.nextInt();
            int newVal = sc.nextInt();
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
            decreaseKey(arr, idx, newVal);
            for (int i = 0; i < n; i++) {
                System.out.print(arr[i] + (i == n - 1 ? "" : " "));
            }
            System.out.println();
        }
        sc.close();
    }
}