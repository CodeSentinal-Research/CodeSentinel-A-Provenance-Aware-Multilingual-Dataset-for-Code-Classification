import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        System.out.println(equilibriumIndex(arr, n));
    }

    static int equilibriumIndex(int arr[], int n) {
        int sum = 0;
        int leftSum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
        }
        for (int i = 0; i < n; i++) {
            sum -= arr[i];
            if (leftSum == sum) {
                return i;
           }
        }
        return -1;
    }
}
