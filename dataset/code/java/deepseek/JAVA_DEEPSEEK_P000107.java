import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        boolean isSorted = true;
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {
                isSorted = false;
                break;
           }
        }
        System.out.println(isSorted ? "Sorted" : "Not Sorted");
    }
}
