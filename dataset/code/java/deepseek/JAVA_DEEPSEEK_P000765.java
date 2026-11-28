import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = scanner.nextInt();
        }
        System.out.println(isMaxHeap(nums, n));
    }

    public static boolean isMaxHeap(int[] arr, int n) {
        // leaf nodes are always heap
        for (int i = n / 2; i >= 1; i--) {
            int j = 2 * i;
            // parent is greater than its children
            if (arr[i - 1] < arr[j - 1]) {
                return false;
           }
            // if right child exists and is greater than left child
            if (j < n - 1 && arr[i - 1] < arr[j]) {
                return false;
            }
        }
        return true;
    }
}
