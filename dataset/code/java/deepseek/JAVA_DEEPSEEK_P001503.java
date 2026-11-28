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
        System.out.println(minAdjacentSwaps(arr, K));
    }

    public static int minAdjacentSwaps(int[] arr, int k) {
        int n = arr.length;
        int[] count = new int[n + 1];
        for (int i = 0; i < n; i++) {
            count[arr[i]]++;
        }
        int start = 0;
        for (int end = 0; end < n; end++) {
            if (count[arr[end]] >= k) {
                while (count[arr[start]] >= k) {
                    start++;
                }
                if (end - start + 1 == k) {
                    return 1;
                }
            }
        }
        return -1;
    }
}
