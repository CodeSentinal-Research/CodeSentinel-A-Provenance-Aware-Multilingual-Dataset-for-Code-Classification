import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int k = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        int missing = 0;
        int i = 0;
        while (missing < k) {
            if (arr[i] <= 0) {
                i++;
                continue;
            }
            if (i == 0 || arr[i] > arr[i - 1] + 1) {
                missing++;
                if (missing == k) {
                    System.out.println(arr[i - 1] + 1);
                    return;
                }
            }
            i++;
        }
        System.out.println(arr[n - 1] + k - missing);
    }
}
