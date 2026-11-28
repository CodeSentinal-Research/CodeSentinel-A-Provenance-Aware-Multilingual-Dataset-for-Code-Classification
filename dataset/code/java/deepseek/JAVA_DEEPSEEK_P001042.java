import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        scanner.close();
        printLeafNodes(arr, 0, n - 1);
    }

    private static void printLeafNodes(int[] arr, int start, int end) {
        if (start > end) {
            return;
        }
        int mid = (start + end) / 2;
        printLeafNodes(arr, start, mid);
        printLeafNodes(arr, mid + 1, end);
        if (mid == end) {
            System.out.println(arr[mid]);
        }
    }
}
