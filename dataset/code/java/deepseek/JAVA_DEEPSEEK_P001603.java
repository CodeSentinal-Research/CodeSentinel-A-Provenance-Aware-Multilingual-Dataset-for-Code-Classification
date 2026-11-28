import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int x = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        scanner.close();
        System.out.println(findMinPrefixLength(arr, x));
    }

    private static int findMinPrefixLength(int[] arr, int x) {
        int left = 0, right = arr.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (getSum(arr, mid) < x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left == arr.length ? -1 : left;
    }

    private static int getSum(int[] arr, int prefixLength) {
        int sum = 0;
        for (int i = 0; i < prefixLength; i++) {
            sum += arr[i];
        }
        return sum;
    }
}
