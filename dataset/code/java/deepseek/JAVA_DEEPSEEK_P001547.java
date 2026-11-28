import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = scanner.nextInt();
        }
        scanner.close();
        System.out.println(maxOdd(arr, K));
    }

    public static int maxOdd(int[] arr, int k) {
        int max = Integer.MIN_VALUE;
        int count = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] % 2 != 0) {
                count++;
            }
            if (i >= k - 1) {
                if (arr[i - k + 1] % 2 != 0) {
                    count--;
                }
            }
            if (i >= k - 1 && arr[i] % 2 != 0 && count > max) {
                max = count;
            }
        }
        return max;
    }
}
