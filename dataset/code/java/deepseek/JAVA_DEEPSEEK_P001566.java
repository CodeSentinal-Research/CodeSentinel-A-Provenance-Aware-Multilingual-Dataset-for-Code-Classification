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
        scanner.close();
        printMinimums(arr, k);
    }

    public static void printMinimums(int[] arr, int k) {
        Deque<Integer> deque = new LinkedList<>();
        for (int i = 0; i < k; i++) {
            while (!deque.isEmpty() && arr[i] < arr[deque.peekLast()]) {
                deque.pollLast();
            }
            deque.addLast(i);
        }
        for (int i = k; i < arr.length; i++) {
            if (deque.peekFirst() == i - k) {
                deque.pollFirst();
            }
            while (!deque.isEmpty() && arr[i] < arr[deque.peekLast()]) {
                deque.pollLast();
            }
            deque.addLast(i);
            System.out.println(arr[deque.peekFirst()]);
        }
    }
}
