import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int x = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        scanner.close();
        System.out.println(findSmallestIndex(arr, x));
    }

    private static int findSmallestIndex(int[] arr, int x) {
        int prefixSum = 0;
        int smallestIndex = -1;
        for (int i = 0; i < arr.length; i++) {
            prefixSum += arr[i];
            if (prefixSum >= x) {
                smallestIndex = i + 1;
                break;
            }
        }
        return smallestIndex;
    }
}
