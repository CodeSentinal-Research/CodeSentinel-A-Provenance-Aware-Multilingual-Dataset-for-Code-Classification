import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        System.out.println(findFixedPoint(arr, 0, n - 1));
    }

    private static int findFixedPoint(int[] arr, int low, int high) {
        if (high >= low) {
            int mid = low + (high - low) / 2;
            if (mid == arr[mid])
                return mid;
            if (mid > arr[mid])
                return findFixedPoint(arr, (mid + 1), high);
            return findFixedPoint(arr, low, (mid - 1));
        }
        return -1;
    }
}
