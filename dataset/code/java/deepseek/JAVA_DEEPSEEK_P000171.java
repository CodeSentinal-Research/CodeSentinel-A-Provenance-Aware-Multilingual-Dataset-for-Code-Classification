import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        segregate(arr, n);
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    public static void segregate(int[] arr, int n) {
        int count = 0;  // Counts the number of zeros in arr

        // Traverse the given array count number of zeros
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                count++;
            }
        }

        // Loop fills the arr[i] with 'count' zeros
        for (int i = 0; i < count; i++) {
            arr[i] = 0;
        }

        // Loop fills remaining arr[i] with 1s
        for (int i = count; i < n; i++) {
            arr[i] = 1;
        }
    }
}
