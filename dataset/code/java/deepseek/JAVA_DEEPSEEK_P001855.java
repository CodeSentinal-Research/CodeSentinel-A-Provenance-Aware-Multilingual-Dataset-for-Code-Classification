import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        System.out.println(minInsertions(arr, n));
    }

    static int minInsertions(int[] arr, int n) {
        int[] temp = Arrays.copyOf(arr, n);
        Arrays.sort(temp, 0, n);
        return minInserts(arr, temp, 0, n - 1);
    }

    static int minInserts(int[] arr, int[] temp, int start, int end) {
        if (start == end) {
            return 0;
        }
        if (start + 1 == end) {
            return arr[start] > arr[end] ? 1 : 0;
        }
        int k = findRoot(temp, start, end);
        int left = minInserts(arr, temp, start, k);
        int right = minInserts(arr, temp, k + 1, end);
        return left + right + (arr[k] > temp[end] ? 1 : 0);
    }

    static int findRoot(int[] temp, int start, int end) {
        int mid = (start + end) / 2;
        while (start < end) {
            mid = (start + end) / 2;
            if (temp[mid] > temp[end]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }
        return start;
    }
}
