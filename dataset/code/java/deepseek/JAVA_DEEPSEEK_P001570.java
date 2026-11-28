import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextLong();
        }
        scanner.close();
        System.out.println(longestSubarray(arr));
    }

    private static long longestSubarray(long[] arr) {
        int n = arr.length;
        long maxProduct = arr[0];
        long minProduct = arr[0];
        long maxLength = 1;
        long currentLength = 1;
        long result = 1;

        for (int i = 1; i < n; i++) {
            if (arr[i] > 0) {
                currentLength++;
                if (maxProduct == 0) {
                    maxProduct = arr[i];
                } else {
                    maxProduct *= arr[i];
                }
                if (minProduct > 0) {
                    minProduct *= arr[i];
                } else {
                    long temp = minProduct;
                    minProduct = maxProduct;
                    maxProduct = temp * arr[i];
                }
            } else {
                currentLength = 1;
                if (arr[i] < 0) {
                    long temp = maxProduct;
                    maxProduct = minProduct;
                    minProduct = temp * arr[i];
                } else {
                    maxProduct = minProduct = 1;
                }
            }
            if (maxProduct > result) {
                result = maxProduct;
            }
            if (maxProduct == 0) {
                maxProduct = minProduct = 1;
                currentLength = 1;
            }
        }
        return Math.max(maxLength, result);
    }
}
