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

        int left = 0, right = n - 1;
        while (left < right) {
            if (arr[left] == 0) {
                left++;
            } else if (arr[right] == 0) {
                right--;
            } else {
                arr[left] *= 2;
                arr[right] = 0;
                left++;
                right--;
            }
        }

        if (arr[left] != 0) {
            System.out.println(arr[left]);
        } else {
            System.out.println(0);
        }
    }
}
