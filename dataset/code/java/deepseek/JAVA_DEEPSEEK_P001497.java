import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        rearrangeArray(arr);

        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    public static void rearrangeArray(int[] arr) {
        int n = arr.length;
        int[] positive = new int[n / 2];
        int[] negative = new int[n / 2];

        int posIndex = 0;
        int negIndex = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) {
                negative[negIndex++] = arr[i];
            } else {
                positive[posIndex++] = arr[i];
            }
        }

        for (int i = 0; i < n / 2; i++) {
            arr[i] = negative[i];
        }

        for (int i = n / 2; i < n; i++) {
            arr[i] = positive[i - n / 2];
        }
    }
}
