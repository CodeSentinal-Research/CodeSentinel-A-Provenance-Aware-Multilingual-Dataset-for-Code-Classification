import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr1 = new int[n];
        int[] arr2 = new int[n];
        for (int i = 0; i < n; i++) {
            arr1[i] = scanner.nextInt();
        }
        for (int i = 0; i < n; i++) {
            arr2[i] = scanner.nextInt();
        }
        Arrays.sort(arr1);
        Arrays.sort(arr2);
        int[] result = new int[n];
        int i = 0, j = n - 1;
        while (i <= j) {
            if (i % 2 == 0) {
                result[i] = arr2[j--];
            } else {
                result[i] = arr1[j--];
            }
            i++;
        }
        for (int num : result) {
            System.out.print(num + " ");
        }
    }
}
