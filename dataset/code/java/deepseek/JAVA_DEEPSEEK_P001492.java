import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        int K = scanner.nextInt();
        int X = scanner.nextInt();
        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = scanner.nextInt();
        }
        List<Integer> result = findClosestElements(arr, N, K, X);
        for (int i : result) {
            System.out.println(i);
        }
    }

    public static List<Integer> findClosestElements(int[] arr, int N, int K, int X) {
        List<Integer> result = new ArrayList<>();
        int left = 0;
        int right = N - 1;
        while (right - left >= K) {
            if (Math.abs(arr[left] - X) <= Math.abs(arr[right] - X)) {
                left++;
            } else {
                right--;
            }
        }
        for (int i = left; i <= right; i++) {
            result.add(arr[i]);
        }
        return result;
    }
}
