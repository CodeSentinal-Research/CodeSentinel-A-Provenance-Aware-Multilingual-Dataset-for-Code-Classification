import java.util.Scanner;
import java.util.Deque;
import java.util.LinkedList;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        System.out.println(maxInFirstWindow(arr, k));
    }

    public static int maxInFirstWindow(int[] arr, int k) {
        Deque<Integer> deque = new LinkedList<>();
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < k; i++) {
            while (!deque.isEmpty() && arr[i] >= deque.peekLast()) {
                deque.pollLast();
            }
            deque.addLast(arr[i]);
        }
        max = Math.max(max, deque.peekFirst());
        for (int i = k; i < arr.length; i++) {
            if (deque.peekFirst() == arr[i - k]) {
                deque.pollFirst();
            }
            while (!deque.isEmpty() && arr[i] >= deque.peekLast()) {
                deque.pollLast();
            }
            deque.addLast(arr[i]);
            max = Math.max(max, deque.peekFirst());
        }
        return max;
    }
}
