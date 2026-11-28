import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }
        findMissingAndRepeating(arr, n);
    }

    public static void findMissingAndRepeating(int[] arr, int n) {
        int[] count = new int[n+1];
        int missing = 0, repeating = 0;
        for (int i = 0; i < n; i++) {
            count[arr[i]]++;
        }
        for (int i = 1; i <= n; i++) {
            if (count[i] == 0) {
                missing = i;
           } else if (count[i] > 1) {
                repeating = i;
            }
        }
        System.out.println("Missing number: " + missing);
        System.out.println("Repeating number: " + repeating);
    }
}
