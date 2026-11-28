import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        rearrange(arr, n);
        for (int i : arr) {
            System.out.print(i + " ");
        }
    }

    public static void rearrange(int[] arr, int n) {
        int i = -1, j = 0;
        while (j != n) {
            if (arr[j] < 0) {
                i++;
                int temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            j++;
        }
        if (i == -1)
            return;
        int pos = i + 1, neg = 0;
        while (pos < n && arr[neg] < 0) {
            int temp;
            temp = arr[neg];
            arr[neg] = arr[pos];
            arr[pos] = temp;
            pos++;
            neg += 2;
        }
    }
}