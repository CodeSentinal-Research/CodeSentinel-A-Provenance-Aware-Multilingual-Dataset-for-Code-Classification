import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        scanner.close();
        System.out.println(minOperations(arr));
    }

    public static int minOperations(int[] arr) {
        int operations = 0;
        int sum = 0;
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
        }
        if (sum == 0) {
            return 0;
        } else if (sum < 0) {
            return -sum / 2;
        } else {
            return sum / 2;
        }
    }
}
