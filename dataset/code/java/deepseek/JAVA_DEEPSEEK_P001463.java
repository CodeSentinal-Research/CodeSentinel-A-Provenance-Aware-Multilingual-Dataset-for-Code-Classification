import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int value = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] != value) {
                arr[count++] = arr[i];
            }
        }
        System.out.println(count);
        for (int i = 0; i < count; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}
