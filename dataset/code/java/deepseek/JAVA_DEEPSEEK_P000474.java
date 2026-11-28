import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        System.out.println(findMaxInBitonicArray(arr));
    }

    private static int findMaxInBitonicArray(int[] arr) {
        int start = 0;
        int end = arr.length - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (mid < end && arr[mid] < arr[mid + 1]) {
                start = mid + 1;
            } else if (mid > start && arr[mid] < arr[mid - 1]) {
                end = mid - 1;
            } else {
                return arr[mid];
            }
        }
        return -1;
    }
}
