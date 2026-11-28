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
        int result = findMinPrefixLength(arr, x);
        System.out.println(result == -1 ? "No such prefix exists" : result);
    }

    private static int findMinPrefixLength(int[] arr, int x) {
        int left = 0, right = arr.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (getSum(arr, mid) >= x) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    private static int getSum(int[] arr, int prefixLength) {
        int sum = 0;
        for (int i = 0; i < prefixLength; i++) {
            sum += arr[i];
        }
        return sum;
    }
}
