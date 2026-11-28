import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            arr[i] = scanner.nextInt();
        }
        System.out.println(findMissing(arr, n));
    }

    private static int findMissing(int[] arr, int n) {
        int diff = (arr[n - 2] - arr[0]) / n;
        for (int i = 0; i < n - 2; i++) {
            if (arr[i + 1] - arr[i] != diff) {
                return arr[i] + diff;
            }
        }
        return -1;
    }
}
