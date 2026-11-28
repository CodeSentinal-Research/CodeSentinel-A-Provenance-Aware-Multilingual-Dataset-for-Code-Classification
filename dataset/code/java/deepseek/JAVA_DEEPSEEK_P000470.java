import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int target = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        System.out.println(findMinDifferenceElement(arr, target));
    }

    private static int findMinDifferenceElement(int[] arr, int target) {
        return arr[Arrays.binarySearch(arr, target) < 0 ? -Arrays.binarySearch(arr, target) - 1 : Arrays.binarySearch(arr, target)];
    }
}
