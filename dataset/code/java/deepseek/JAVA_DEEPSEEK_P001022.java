import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        int i = scanner.nextInt();
        int newValue = scanner.nextInt();
        if (newValue > arr[i]) {
            System.out.println("New value is greater than current value. Cannot update.");
        } else {
            arr[i] = newValue;
            while (i > 0 && arr[i] < arr[(i - 1) / 2]) {
                swap(arr, i, (i - 1) / 2);
                i = (i - 1) / 2;
            }
            System.out.println(java.util.Arrays.toString(arr));
        }
    }

    private static void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
