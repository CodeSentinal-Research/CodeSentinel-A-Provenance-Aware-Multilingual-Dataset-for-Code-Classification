import java.util.Scanner;
import java.util.Deque;
import java.util.ArrayDeque;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        System.out.println(findMin(arr, k));
    }

    public static int findMin(int[] arr, int k) {
        Deque<Integer> deque = new ArrayDeque<>();
        int n = arr.length;
        for (int i = 0; i < k; i++) {
            while (!deque.isEmpty() && arr[i] < deque.peekLast()) {
                deque.pollLast();
            }
            deque.addLast(arr[i]);
        }
        int min = deque.peekFirst();
        for (int i = k; i < n; i++) {
            if (arr[i] < deque.peekFirst()) {
                min = arr[i];
            }
            if (arr[i - k] == deque.peekFirst()) {
                deque.pollFirst();
            } else {
                deque.pollFirst();
                deque.addLast(arr[i]);
            }
        }
        return min;
    }
}
